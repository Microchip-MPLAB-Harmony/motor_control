define(['util', 'searchEngine', 'searchPresenter', 'searchHistoryItems', 'localization', 'jquery'], function(util, searchEngine, searchPresenter, searchHistory, i18n, $) {

    /*
    	Oxygen WebHelp Plugin
    	Copyright (c) 1998-2022 Syncro Soft SRL, Romania.  All rights reserved.
    */

    var txt_browser_not_supported = "Your browser is not supported. Use of Mozilla Firefox is recommended.";

    if(typeof String.prototype.trim !== 'function') {
        String.prototype.trim = function() {
            return $.trim(this);
        }
    }

    $(document).ready(function () {
        var searchQuery = '';
        try {
            searchQuery = util.getParameter('searchQuery');
            searchQuery = decodeURIComponent(searchQuery);
            searchQuery = searchQuery.replace(/\+/g, " ");
            if (searchQuery.trim()!='' && searchQuery!==undefined && searchQuery!='undefined') {
                $('#textToSearch').val(searchQuery);
                util.debug("Execute search");
                executeQuery();
                util.debug("Executed search");
            }
        } catch (e) {
            util.debug("#########", e);
        }

        $('.gcse-searchresults-only').attr('data-queryParameterName', 'searchQuery');

        // Select page from parameter in the pages widget
        window.onpopstate = function(event) {
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

            searchEngine.onPageChangedHandler(pageToShow, searchQuery, searchSuccess, searchFailed);

            // Update the active page
            $('.pagination li[class~="active"]').removeClass("active");
            $('.pagination li[data-lp="' + pageToShow + '"]:not([class~="prev"]):not([class~="next"])').addClass("active");
        };

        $('#searchForm').on('submit', function(event){
            util.debug('submit form....');
            if ($('#textToSearch').val().trim()=='') {
                event.preventDefault();
                event.stopPropagation();

                return false;
            }
        });
    });


    /**
     * @description Search using Google Search if it is available, otherwise use our search engine to execute the query
     * @return {boolean} Always return false
     */
    function executeQuery() {
        util.debug("executeQuery");
        var input = document.getElementById('textToSearch');
        try {
            var element = google.search.cse.element.getElement('searchresults-only0');
        } catch (e) {
            util.debug(e);
        }
        if (element != undefined) {
            if (input.value == '') {
                element.clearAllResults();
            } else {
                element.execute(input.value);
            }
        } else {
            executeSearchQuery($("#textToSearch").val());
        }

        return false;
    }

    /**
     * Execute search query with internal search engine.
     *
     * @description This function find all matches using the search term
     * @param {HTMLObjectElement} ditaSearch_Form The search form from WebHelp page as HTML Object
     */
    function executeSearchQuery(query) {
        util.debug('SearchToc(..)');

        // Check browser compatibility
        if (navigator.userAgent.indexOf("Konquerer") > -1) {
            alert(i18n.getLocalization(txt_browser_not_supported));
            return;
        }

        searchEngine.performSearchOperation(query, searchSuccess, searchFailed);
    }

    /**
     * Handler when the page is changed.
     * 
     * @param {Integer} pageToShow The new page to show.
     * @param {String} query The query string the user typed in the search input field.
     */
    function onPageChangedHandler(pageToShow, query) {
        searchEngine.onPageChangedHandler(pageToShow, query, searchSuccess, searchFailed);
    }

    /**
     * Handler when the search operation is executed successfully.
     * 
     * @param {SearchResult} result The result of the serach.
     */
    function searchSuccess(result) {
        // Add search query to history
        searchHistory.addSearchQueryToHistory(result.meta.originalSearchExpression);
        searchPresenter.displayResults(result, onPageChangedHandler);
    }

    /**
     * Handler when the search operation fails.
     * 
     * @param {String} error The error message to be displayed.
     */
    function searchFailed(error) {
        searchPresenter.displayErrors(error);
    }
    
});
