define(['options', 'util', 'searchEngine'], function(options, util, searchEngine) {

    /**
     * Object used to display the search results in the search page.
     * 
     * @param {SearchMeta} meta Contains additional information for the search result.
     * @param {SearchDocument} documents The matching documents (html pages) for the search result. 
     */
    function SearchResult(meta, documents) {
        this.meta = meta;
        this.documents = documents;
    }

    /**
     * Holds additional information for the search result.
     * 
     * @param {String} searchEngineName The name of the search engine used to retrieve the search result.
     * @param {Integer} totalResults The toatl number of results returned.
     * @param {Integer} currentPage The current page to display.
     * @param {Integer} maxItemsPerPage The maximum number of items that can be displayed on a page.
     * @param {Integer} totalPages The total pages for the search result.
     * @param {String} originalSearchExpression The query string the user typed in the search input field.
     * @param {Boolean} hasSearchExpressionOnlyStopwords <code>true</code> if the search expression contains only stopwords, <code>flase</code> otherwise
     * @param {Boolean} isPhraseSearch  <code>true</code> if phrase search was used, <code>flase</code> otherwise
     * @param {Boolean} isBreadcrumbSupported <code>true</code> if phrase search was used, <code>flase</code> otherwise.
     * @param {Boolean} isMissingWordsSupported <code>true</code> if displaying missing words section in the search page is supported, <code>flase</code> otherwise.
     * @param {Boolean} isSimilarPagesSupported <code>true</code> if displaying similar pages section in the search page is supported, <code>flase</code> otherwise.
     * @param {Boolean} isStarRatingSupported <code>true</code> if displaying star rating section in the search page is supported, <code>flase</code> otherwise.
     */
    function SearchMeta(searchEngineName, totalResults, currentPage, maxItemsPerPage, totalPages, originalSearchExpression, isPhraseSearch, isBreadcrumbSupported, isMissingWordsSupported, isSimilarPagesSupported, isStarRatingSupported) {
        this.searchEngineName = searchEngineName;
        this.totalResults = totalResults;
        this.currentPage = currentPage;
        this.maxItemsPerPage = maxItemsPerPage;
        this.totalPages = totalPages;
        this.originalSearchExpression = originalSearchExpression;
        this.hasSearchExpressionOnlyStopwords = false;
        this.isPhraseSearch = isPhraseSearch;
        this.isBreadcrumbSupported = isBreadcrumbSupported;
        this.isMissingWordsSupported = isMissingWordsSupported;
        this.isSimilarPagesSupported = isSimilarPagesSupported;
        this.isStarRatingSupported = isStarRatingSupported;
    }

    /**
     * An object containing the search result for a single topic/HTML page.
     * 
     * @param {String} linkLocation The URL to the topic.
     * @param {String} title The topic title. 
     * @param {String} shortDescription The topic short description.
     * @param {Array} breadcrumb The breadcrumb for the topic. 
     * @param {Number} scoring The score for the topic. 
     * @param {Array} missingWords The words from the search expression that did not match the topic.
     * @param {Array} matchingWords The words from the search expression that matched the topic.
     */
    function SearchDocument(linkLocation, title, shortDescription, breadcrumb, scoring, missingWords, matchingWords) {
        this.linkLocation = linkLocation;
        this.title = title;
        this.shortDescription = shortDescription;
        this.breadcrumb = breadcrumb;
        this.scoring = scoring;
        this.starWidth = 0;
        this.similarResults = [];
        this.missingWords = missingWords;
        this.matchingWords = matchingWords;
    }

    /**
     * Computes the star rating of a search result item.
     * 
     * @param {SearchDocument} document The search item to compute the score for.
     * @param {Integer} maxDocumentScore The maximum score for all documents.
     * 
     * @returns {Integer} The width for the star rating widget.
     */
    function computeStarRating(document, maxDocumentScore) {
        var hundredPercent = document.scoring + 100 * document.matchingWords.length;
        var documentScore = document.scoring;

        starWidth = (documentScore * 100 / hundredPercent) / (maxDocumentScore / hundredPercent);
        starWidth = starWidth < 10 ? (starWidth + 5) : starWidth;
        
        // Keep the 5 stars format
        if (starWidth > 85) {
            starWidth = 85;
        }

        return starWidth;
    }

    /**
     * Sorts the search result items by scoring, title and short description.
     * 
     * @param {Array} documents 
     */
    function sortResult(documents) {
        // WH-1943 - sort by scoring, title and short description
        documents.sort(function (first, second) {
            var cRes = second.scoring - first.scoring;
            if (cRes == 0) {
                cRes = second.title.localeCompare(first.title);
                if (cRes == 0) {
                    cRes = second.shortDescription.localeCompare(first.shortDescription);
                }
            }
            return cRes;
        });
    }

    /**
     * Compare two result pages to see if there are similar
     * 
     * @param {SearchDocument} document1 Search item from the search result
     * @param {SearchDocument} document2 Search item from the search result
     * 
     * @returns {boolean} true - result pages are similar
     *                    false - result pages are not similar
     */
     function computeSimilarPage(document1, document2) {
        var toReturn = false;

        if (document1 === undefined || document2 === undefined) {
            return toReturn;
        }

        var pageTitle1 = document1.title;
        var pageShortDesc1 = document1.shortDescription;

        var pageTitle2 = document2.title;
        var pageShortDesc2 = document2.shortDescription;

        if (pageTitle1.trim() == pageTitle2.trim() && pageShortDesc1.trim() == pageShortDesc2.trim()) {
            toReturn = true;
        }

        return toReturn;
    }

    /**
     * Computes the search pagination information based on the webehelp parameters.
     * 
     * @returns {Object} An object that holds the page to dispay and the maximum number of itesm for a page.
     */
    function computeSearchPagination() {
        var webhelpEnableSearchPagination = options.getBoolean("webhelp.search.enable.pagination");
        var webhelpSearchNumberOfItems = options.getInteger("webhelp.search.page.numberOfItems");

        if (webhelpEnableSearchPagination !== 'undefined' && webhelpEnableSearchPagination == false) {
            // WH-1470 - Search pagination is disabled
            maxItemsPerPage = Number.MAX_VALUE;
        } else if (typeof webhelpSearchNumberOfItems !== 'undefined') {
            // WH-1471 - Option to control the maximum numbers of items displayed for each page
            maxItemsPerPage = webhelpSearchNumberOfItems;
        }

        // Get the value for the 'page' parameter
        var pageToShow = util.getParameter("page");

        // Set to 1 if it is undefined
        if (pageToShow == undefined || pageToShow == "undefined" || pageToShow == "") {
            pageToShow = 1;
        } else {
            pageToShow = parseInt(pageToShow);
            if (isNaN(pageToShow)) {
                pageToShow = 1;
            }
        }

        return {
            pageToShow: pageToShow,
            maxItemsPerPage: maxItemsPerPage
        }
    }

    /**
     * Set a custom search engine.
     * 
     * @param {Object} customSearchEngine Object that needs to implement the performSearchOperationa and onPageChangedHandler methods.
     */
    function setCustomSearchEngine(customSearchEngine) {
        searchEngine.setCustomSearchEngine(customSearchEngine);
    }

    return {
        SearchResult: SearchResult,
        SearchMeta: SearchMeta,
        SearchDocument: SearchDocument,
        computeStarRating: computeStarRating,
        computeSimilarPage: computeSimilarPage,
        sortResult: sortResult,
        computeSearchPagination: computeSearchPagination,
        setCustomSearchEngine: setCustomSearchEngine
    }

});