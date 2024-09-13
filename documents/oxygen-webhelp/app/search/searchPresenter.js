define(['dom-sanitizer', 'localization', 'options', 'util', 'jquery', 'jquery.highlight', 'jquery.bootpag'], function(domSanitizer, i18n, options, util, $) {

    /**
     * Displyes the error message in the search page.
     * 
     * @param {String} error The error message to display in the search page.
     */
    function displayErrors(error) {
        var searchResultHTML = $('<p/>');
        searchResultHTML.addClass('errorMessage').html(error);

        $('#searchResults').html(searchResultHTML);
    }

    /**
     * Displayes the search result in the search page.
     * 
     * @param {SearchResult} searchResult Object that holds the information to display the search result.
     * @param {Function} onPageChangeHandler Handler for changing the page.
     */
    function displayResults(searchResult, onPageChangeHandler) {
        var meta = searchResult.meta;
        var documents = searchResult.documents;

        if(documents !== undefined && documents.length > 0) {
            var $wh_search_results_items = $('<div/>', {
                class: 'wh_search_results_items'
            });
            
            var $headerHTML = computeSearchHeaderHTML(meta);
            $wh_search_results_items.append($headerHTML);

            var $bodyHTML = computeSearchBodyHTML(meta, documents);
            $wh_search_results_items.append($bodyHTML);

            $('#searchResults').html($wh_search_results_items);
            window.scrollTo(0, 0);

            addPagination(meta, onPageChangeHandler);
        } else {
            var $wh_search_results_items = $();
            if(meta.hasSearchExpressionOnlyStopwords) {
                $wh_search_results_items = $('<div/>');
                var $p = $('<p/>', {
                    class: 'wh_search_results_for'
                }).html(i18n.getLocalization("no_results_only_stop_words1"));
                $wh_search_results_items.append($p);

                $p.html(i18n.getLocalization('no_results_only_stop_words2'));
                $wh_search_results_items.append($p);
            } else {
                $wh_search_results_items = $('<div/>', {
                    class: 'wh_search_results_for'
                }).html(i18n.getLocalization('Search no results') + ' ');
                var $span = $('<span/>', {
                    class: 'wh_search_expression'
                }).text(meta.originalSearchExpression);
                domSanitizer.appendHtmlNode($span,  $wh_search_results_items);
            }
            $('#searchResults').html($wh_search_results_items);
        }
    }

    /**
     * Computes the HTML content for the header section that is displayed in the search results.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * 
     * @returns The HTML content.
     */
    function computeSearchHeaderHTML(meta) {
        // Result for: word1 word2
        var $headerHTML = $('<div/>', {
            class: 'wh_search_results_header'
        });

        var $whSearchResultsHeaderDocs = $('<div/>', {
            class: 'wh_search_results_header_docs'
        }).html(
            meta.totalResults +
            ' ' +
            i18n.getLocalization("Results for:") + ' '
        );

        var $span = $('<span/>', {
            class: 'wh_search_expression'
        }).text(meta.originalSearchExpression);
        domSanitizer.appendHtmlNode($span, $whSearchResultsHeaderDocs);
        domSanitizer.appendHtmlNode($whSearchResultsHeaderDocs, $headerHTML);

        if (typeof meta.currentPage != "undefined" && typeof meta.totalPages != "undefined" && meta.totalPages > 1) {
            var $wh_search_results_header_pages = $('<div/>', {
                class: 'wh_search_results_header_pages'
            }).html(i18n.getLocalization('Page') + ' ' + meta.currentPage + '/' + meta.totalPages);
            $headerHTML.append($wh_search_results_header_pages);
        }

        return $headerHTML;
    }

    /**
     * Computes the HTML content for the actual search items.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {SearchDocument} documents The matching documents from the search result.
     * 
     * @returns The HTML content.
     */
    function computeSearchBodyHTML(meta, documents) {
        var $ol = $('<ol/>', {
            class: 'searchresult',
            start: (meta.currentPage - 1) * meta.maxItemsPerPage + 1
        });

        documents.forEach((d) => {
            var htmlResult = computeSearchItemHTML(meta, d, null);

            $ol.append(htmlResult);

            if (meta.isSimilarPagesSupported && d.similarResults.length > 0) {
                // Add HTML for similar pages
                for (var smPage = 0; smPage < d.similarResults.length; smPage++) {
                    var simHTML = computeSearchItemHTML(meta, d.similarResults[smPage], d.id);
                    $ol.append(simHTML);
                }
            }

        });

        return $ol;
    }

    /**
     * Computes a search result item that will be displayed in the search page.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {SearchDocumnet} document A matching document from the search result.
     * @param {String} similarPageId The id for which the current matching document is simiilar with. Can be null.
     * 
     * @returns The HTML content.
     */
    function computeSearchItemHTML(meta, document, similarPageId) {
        var idLink = 'foundLink' + document.id;
        var idResult = 'foundResult' + document.id;

        var htmlResult = $();        
        if (similarPageId == null) {
            htmlResult = $('<li/>', {
                id: idResult
            });
        } else {
            htmlResult = $('<li/>', {
                id: idResult,
                class: 'similarResult',
                'data-similarTo': 'foundResult' + similarPageId
            });
        }

        var url = computeHighlightUrl(meta, document);
        // The topic title of the search result item
        var $a = $('<a/>', {
            id: idLink,
            href: url,
            class: 'foundResult'
        }).html(document.title);
        htmlResult.append($a);

        if (meta.isBreadcrumbSupported) {
            var $breadcrumbHtml = computeBreadcrumbHTML(document);
            htmlResult.append($breadcrumbHtml);
        }

        var $shortDescriptionHTML = computeShortDescriptionHTML(meta, document);
        htmlResult.append($shortDescriptionHTML);

        var $searchItemAdditionalData = $('<div/>', {
            class: 'searchItemAdditionalData'
        });

        var $searchItemInfo = $('<div/>', {
            class: 'missingAndSimilar'
        });
        if (meta.isMissingWordsSupported) {
            var $missingWordsHTML = computeMissingWordsHTML(document);
            $searchItemInfo.append($missingWordsHTML);
        }

        if (meta.isSimilarPagesSupported && document.similarResults.length > 0) {
            var $similarHTML = $('<a/>', {
                class: 'showSimilarPages'
            }).html(i18n.getLocalization('Similar results') + '...');
            $similarHTML.click(showSimilarResults);
            $searchItemInfo.append($similarHTML);
        }

        $searchItemAdditionalData.append($searchItemInfo);

        if (meta.isStarRatingSupported) {
            var $starRatingHTML = computeStarRatingHTML(meta, document);
            $searchItemAdditionalData.append($starRatingHTML);
        }
        htmlResult.append($searchItemAdditionalData);
        return htmlResult;
    }

    /**
     * Computes the HTML content for the star rating section.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {SearchDocumnet} document A matching document from the search result.
     * 
     * @returns A node that contains the HTML content for the star rating.
     */
    function computeStarRatingHTML(meta, document) {
        // Add rating values for scoring at the list of matches
        var rankingHTML = $("<div/>", {
            id: 'rightDiv'
        });
        if (meta.displayScore) {
            rankingHTML.attr('title', 'Score: ' + document.scoring);
        }

        var rankingStar =
            $('<div/>', {
                id: 'star'
            }).append(
                $('<div/>', {
                    id: 'star0',
                    class: 'star'
                }).append(
                    $('<div/>', {
                        id: 'starCur0',
                        class: 'curr',
                        style: 'width: ' + document.starWidth + 'px'
                    }).append(
                        $('<br/>', {
                            style: 'clear: both;'
                        })
                    )
                )
            );
        rankingHTML.append(rankingStar);
        return rankingHTML;
    }

    /**
     * Computes hightlght URL.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {SearchDocumnet} document A matching document from the search result.
     * 
     * @returns A string that will containt the highlight parameter in the URL.
     */
    function computeHighlightUrl(meta, document) {
        var indexerLanguage = options.getIndexerLanguage();
        var useCJKTokenizing = !!(typeof indexerLanguage != "undefined" && (indexerLanguage == "zh" || indexerLanguage == "ko"));
        var wordsMatchingInTheDocument = document.matchingWords;
        var highlightString = '';

        if(meta.isPhraseSearch) {
            highlightString = meta.originalSearchExpression;
        } else {
            var highlightWords = []
            for (var x in wordsMatchingInTheDocument) {
                if (wordsMatchingInTheDocument[x].length >= 2 || useCJKTokenizing || (indexerLanguage == "ja" && wordsMatchingInTheDocument[x].length >= 1)) {
                    highlightWords.push(wordsMatchingInTheDocument[x]);
                }
            }
            highlightString = highlightWords.toString();
        }

        return document.linkLocation + '?hl=' + encodeURIComponent(highlightString);
    }

    /**
     * Computes the HTML content for the breadcrumb section.
     * 
     * @param {SearchDocumnet} document A matching document from the search result.
     * 
     * @returns A node that contains the HTML content for the breadcrumb.
     */
    function computeBreadcrumbHTML(document) {
        var breadcrumbHtml = $('<div>', {
            class: 'search-breadcrumb',
        });
        var breadcrumb = document.breadcrumb;
        if (breadcrumb !== undefined && breadcrumb.length > 0) {
            var breadcrumbItems = $('<ol>');
            breadcrumb.forEach(function (item) {
                var li = $('<li>');
                var span = $('<span>',
                    {
                        class: 'title'
                    });
                span.append($('<a>',
                    {
                        href: item.relativePath,
                        html: item.title
                    }));
                li.append(span);
                breadcrumbItems.append(li);
            });

            breadcrumbHtml.append(breadcrumbItems);
        }
        return breadcrumbHtml;
    }

    /**
     * Computes the HTML content for short description section.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {SearchDocumnet} document A matching document from the search result.
     * 
     * @returns A node that contains the HTML content for the short description.
     */
    function computeShortDescriptionHTML(meta, document) {
        var $shortDescriptionHTML = $('<div/>', {
            class: 'shortdesclink'
        });
        // Short description
        // Also check if we have a valid description
        if ((document.shortDescription != "null" && document.shortDescription != '...')) {
            $shortDescriptionHTML.html(document.shortDescription);

            // Highlight the search words in short description
            if(meta.isPhraseSearch) {
                $shortDescriptionHTML.highlight(meta.originalSearchExpression, 'search-shortdescription-highlight');
            } else {
                for (var si = 0; si < document.matchingWords.length; si++) {
                    var sw = document.matchingWords[si];
                    $shortDescriptionHTML.highlight(sw, 'search-shortdescription-highlight');
                }
            }
        }
        return $shortDescriptionHTML;
    }

    /**
     * Computes the HTML content for missing words section.
     * 
     * @param {SearchDocumnet} document A matching document from the search result.
     * 
     * @returns A node that contains the HTML content for the missing words.
     */
    function computeMissingWordsHTML(document) {
        var $missingWordsHTML = $('<div/>', {
            class: 'wh_missing_words'
        });
        // Missing words
        if (document.missingWords.length > 0) {
            $missingWordsHTML.html(i18n.getLocalization('missing') + ' : ');

            for (var widx = 0; widx < document.missingWords.length; widx++) {
                var $span = $('<span/>', {
                    class: 'wh_missing_word'
                }).text(document.missingWords[widx]);
                domSanitizer.appendHtmlNode($span, $missingWordsHTML);
                $missingWordsHTML.append(' ');
            }
        }

        return $missingWordsHTML;
    }

    /**
     * Adds the pagination widget at the end of the search page.
     * 
     * @param {SearchMeta} meta Object that holds additional information about the search result.
     * @param {Function} onPageChangeHandler Handler for changing the page.
     */
    function addPagination(meta, onPageChangeHandler) {
        if (meta.totalPages > 1) {
            // Add pagination widget
            $('#wh-search-pagination').bootpag({
                total: meta.totalPages,               // total pages
                page: meta.currentPage,               // default page
                maxVisible: meta.maxItemsPerPage,     // visible pagination
                leaps: false,                         // next/prev leaps through maxVisible
                next: i18n.getLocalization("next.page"),
                prev: i18n.getLocalization("prev.page")
            }).on("page", function(event, num){
                util.debug("Display page with number: ", num);

                // Replace or add the page query
                var oldPage = util.getParameter("page");
                var oldQuery = window.location.search;
                var oldHref = window.location.href;
                var oldLocation = oldHref.substr(0, oldHref.indexOf(oldQuery));

                var newQuery = "";
                if (oldPage == undefined || oldPage == "undefined" || oldPage == "") {
                    newQuery = oldQuery + "&page=" + num;
                } else {
                    var re = new RegExp("(\\?|&)page\=" + oldPage);
                    newQuery = oldQuery.replace(re, "$1page="+num);
                }

                window.history.pushState("searchPage" + num, document.title, oldLocation + newQuery);
                onPageChangeHandler(num, meta.originalSearchExpression);
            });
        }
        // make bootpag compatible with Bootstrap 4.0
        $('#wh-search-pagination').find('li').addClass('page-item');
        $('#wh-search-pagination').find('a').addClass('page-link');

        $("#search").trigger('click');
    }

    /**
     * @description Show similar results that are hidden by default
     */
    function showSimilarResults() {
        var parentLiElement = $(this).parents('li[id]');
        var currentResultId = parentLiElement.attr('id');

        $('[data-similarTo="' + currentResultId + '"]').toggle();
        $(this).toggleClass('expanded');
    }

    return {
        displayErrors: displayErrors,
        displayResults: displayResults
    }

});