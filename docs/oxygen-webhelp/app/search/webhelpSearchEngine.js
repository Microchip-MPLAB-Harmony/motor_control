define(['nwSearchFnt', 'searchAPI'], function(nwSearch, SearchAPI) {

    /**
     * Cache the search result. The nwSearch function does not use pagitnation when returning
     * the search result.
     */
    var lastSearchResult;

    /**
     * Performs the search operation.
     * 
     * @param {String} query The search input string from the user.
     * @param {Function} successHandler Will be called if the search operation is executed successfully. 
     *                                  The parameter needs to have the type of SearchApi.SearchResult 
     * @param {Function} errorHandler Will be called if the search operation is executed successfully. 
     *                                The parameter needs to have the type of String. 
     */
    function performSearchOperation(query, successHandler, errorHandler) {
        nwSearch.performSearch(query, function(result) {
            if (result.searchExpression.trim().length > 0 || result.excluded.length > 0) {
                var formattedResult = format(result);
                lastSearchResult = Object.assign({}, formattedResult);
                formattedResult.documents = formattedResult.documents.slice((formattedResult.meta.currentPage - 1) * formattedResult.meta.maxItemsPerPage, formattedResult.meta.currentPage * formattedResult.meta.maxItemsPerPage);
                successHandler(formattedResult);
            } else {
                var error = result.error;
                if (typeof error != "undefined" && error.length > 0) {
                    errorHandler(error);
                }
            }
        });
    }

    /**
     * Handleer when the page is changed in the search page.
     * 
     * @param {Integer} pageToShow The page to be dispalyed.
     * @param {String} query The search input string from the user.
     * @param {Function} successHandler Will be called if the search operation is executed successfully. 
     *                                  The parameter needs to have the type of SearchApi.SearchResult 
     * @param {Function} errorHandler Will be called if the search operation is executed successfully. 
     *                                The parameter needs to have the type of String. 
     */
    function onPageChangedHandler(pageToShow, query, successHandler, errorHandler) {
        lastSearchResult.meta.currentPage = pageToShow;
        var documents = lastSearchResult.documents.slice((pageToShow - 1) * lastSearchResult.meta.maxItemsPerPage, pageToShow * lastSearchResult.meta.maxItemsPerPage);
        var formattedResult = {
            meta: lastSearchResult.meta,
            documents: documents
        }
        successHandler(formattedResult);
    }

    /**
     * Fortmats the search engine ginven result to the SearchApi.SearchResult object
     * 
     * @param {Object} result The search result of the search engine.
     *  
     * @returns An object of SearchApi.SearchResult used by the WebHelp search page to display the results.
     */
    function format(result) {
        var searchDocumentItems = [];
        if(result.documents != undefined && result.documents.length > 0) {
            var allSearchWords = result.searchExpression.split(" ");
            var documents = result.documents.map( (d) => {
                var missingWords = [];
                allSearchWords.forEach(function (word) {
                    if (d.words.indexOf(word) == -1) {
                        missingWords.push(word);
                    }
                });
                return new SearchAPI.SearchDocument(d.relativePath, d.title, d.shortDescription, d.breadcrumb, d.scoring, missingWords, d.words);
            });
    
    
            SearchAPI.sortResult(documents);
            var maxDocumentScore = documents[0].scoring;
            var docWithSimilarResult = {};
            documents.forEach((d, index) => {
                var starWidth = SearchAPI.computeStarRating(d, maxDocumentScore);
                d.starWidth = starWidth;
    
                d.id = index;
    
                var isSimilar = SearchAPI.computeSimilarPage(d, documents[index - 1]);
                if (isSimilar) {
                    docWithSimilarResult.similarResults.push(d);
                } else {
                    docWithSimilarResult = d;
                    searchDocumentItems.push(d);
                }
    
            });
        }

        var pagination = SearchAPI.computeSearchPagination();
        var totalPages = parseInt(searchDocumentItems.length / pagination.maxItemsPerPage) + 1;
        var meta = new SearchAPI.SearchMeta("WebHelp", searchDocumentItems.length, pagination.pageToShow, pagination.maxItemsPerPage ,totalPages, result.originalSearchExpression, result.isPhraseSearch, true, true, true, true);
        if(result.searchExpression.length == 0 && result.excluded.length > 0) {
            meta.hasSearchExpressionOnlyStopwords = true;
        }

        return new SearchAPI.SearchResult(meta, searchDocumentItems);
    }

    return {
        performSearchOperation: performSearchOperation,
        onPageChangedHandler: onPageChangedHandler
    }

});