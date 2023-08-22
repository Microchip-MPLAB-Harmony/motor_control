define(['webhelpSearchEngine'], function(webhelpSearchEngine) {

    /**
     * Possible search engines available in WebHelp.
     */
    var SearchEngine = {
        WEBHELP: "Webhelp",
        CUSTOM: "Custom"
    }

    /**
     * The current search engine to be used when the search operation is triggered.
     */
    var currentSearchEngine = SearchEngine.WEBHELP;

    /**
     * Object that holds the custom search engine.
     */
    var customSearchEngine = undefined;

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
        if (currentSearchEngine === SearchEngine.CUSTOM) {
            customSearchEngine.performSearchOperation(query, successHandler, errorHandler);
        } else {
            webhelpSearchEngine.performSearchOperation(query, successHandler, errorHandler);
        }
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
        if (currentSearchEngine === SearchEngine.CUSTOM) {
            customSearchEngine.onPageChangedHandler(pageToShow, query, successHandler, errorHandler);
        } else {
            webhelpSearchEngine.onPageChangedHandler(pageToShow, query, successHandler, errorHandler);
        }
    }

    /**
     * Set a custom search engine.
     * 
     * @param {Object} customSearchEngine Object that needs to implement the performSearchOperationa and onPageChangedHandler methods.
     */
    function setCustomSearchEngine(customEngine) {
        customSearchEngine = customEngine;
        currentSearchEngine = SearchEngine.CUSTOM;
    }

    return {
        setCustomSearchEngine: setCustomSearchEngine,
        performSearchOperation: performSearchOperation,
        onPageChangedHandler: onPageChangedHandler
    }

});