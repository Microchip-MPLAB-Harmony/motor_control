define(["options", "dom-sanitizer", 'util', 'jquery', 'jquery.highlight'], function(options, domSanitizer, util, $) {
    // Add some Bootstrap classes when document is ready
    var highlighted = false;

    var DEFAULT_MARGIN_STICKY_HEADER_DISABLED = 20;

    /* WH-2521 - Mark the document when it was fully loaded.
	 * This will allow us, for example, to apply transitions only if the document has been fully loaded.
     * Otherwise, there will be color transitions between styles from different CSS files noticeable during page loading. */
	$(document).ready(function () {
        $('html > body').addClass('doc-ready');
    });

    $(document).ready(function () {
        var scrollPosition = $(window).scrollTop();
        handlePublicationTocPosition(scrollPosition);
        handleTopicTocPosition(scrollPosition);

        $(window).scroll(function() {
            scrollPosition = handlePublicationTocPosition(scrollPosition);
            handleTopicTocPosition(scrollPosition);
        });
        $(window).resize(function(){
            $("#wh_publication_toc").removeAttr('style');
            scrollPosition = handlePublicationTocPosition(scrollPosition);
            handleTopicTocPosition(scrollPosition);
        });
        
        // WH-2740 Current topic should always be selected and visible in the publication toc
        displayActiveTopicInPublicationToc();
        
        // Show/hide the button which expands/collapse the subtopics
        // if there are at least two subtopics in a topic
        var countSubtopics = $('.topic.nested1').length;
        var countSections = $('section.section .title').length;
        if(countSubtopics > 1 || countSections >1){
            $('.webhelp_expand_collapse_sections').show();
        }

        // WH-231
        // Expanding the side-toc
        $('.dots-before').click(function(){
            $(this).siblings('.hide-before').show();
            $(this).hide();
        });

        $('.dots-after').click(function(){
            $(this).siblings('.hide-after').show();
            $(this).hide();
        });

		// WH-2209
        var showZoomedImage = options.getBoolean("webhelp.show.full.size.image");
        if (showZoomedImage) {
            // Get the image and insert it inside the modal - use its "alt" text as a caption
            $.each( $('img.image:not([usemap])'), function (e) {
                 var parentElement = $(this).parent().get(0).tagName;
                 if(this.naturalWidth > this.width && parentElement.toLowerCase() != 'a'){
                     $(this).addClass('zoom');
                 }
             });
            $('.zoom').click(function(){
                $('#modal_img_large').css("display","block");
                $('#modal_img_container').append("<img class=\"modal-content\" id=\"modal-img\" alt=\"\" />"); 
                $("#modal-img").attr('src',$(this).attr('src') );
                $("#caption").text( domSanitizer.sanitize($(this).attr('alt')) );
            });
        }

        // When the user clicks on (x), close the modal
        $(".modal .close").click(function(){
            $(".modal").css("display","none");
        });
        $(document).keyup(function(e) {
            if (e.keyCode == 27 && $('#modal_img_large').is(":visible")) { // escape key maps to keycode `27`
               $(".modal").css("display","none");
           }
       });

        // Navigational links and print
        $('#topic_navigation_links .navprev>a').addClass("oxy-icon oxy-icon-arrow-left");
        $('#topic_navigation_links .navnext>a').addClass("oxy-icon oxy-icon-arrow-right");
        $('.wh_print_link button').addClass('oxy-icon oxy-icon-print');

        // Hide sideTOC when it is empty
        var sideToc = $('#wh_publication_toc');
        var pageToc = $('#wh_topic_toc');
        if (sideToc !== undefined) {
            var sideTocChildren = sideToc.find('*');
            if (sideTocChildren.length == 0) {
                sideToc.css('display', 'none');

                // The topic content should span on all 12 columns
                sideToc.removeClass('col-lg-4 col-md-4 col-sm-4 col-xs-12');
                var topicContentParent = $('.wh_topic_content').parent();
                if (topicContentParent !== undefined && pageToc == undefined) {
                    topicContentParent.removeClass(' col-lg-8 col-md-8 col-sm-8 col-xs-12 ');
                    topicContentParent.addClass(' col-lg-12 col-md-12 col-sm-12 col-xs-12 ');
                }
            } else {
                /* WH-1518: Check if the tooltip has content. */
                var emptyShortDesc = sideToc.find('.topicref .wh-tooltip .shortdesc:empty');
                if (emptyShortDesc.length > 0) {
                    var tooltip = emptyShortDesc.closest('.wh-tooltip');
                    tooltip.remove();
                }
            }
        }
        
        // Show the close topic toc button.
        if(pageToc.length) {
            $('#wh_close_topic_toc_button').removeClass("d-none");
            $('#wh_close_topic_toc_button').addClass("d-lg-block");
        }
        
        // Show the close publication toc button.
        if(sideToc.length) {
            $('#wh_close_publication_toc_button').removeClass("d-none");
            $('#wh_close_publication_toc_button').addClass("d-md-block");
        }
        
        // WH-2482 Handler for the button that closes the topic toc.
        $('#wh_close_topic_toc_button').click(function() {
            // Check page toc is in DOM.
            if(pageToc.length) {
                var topicContentColumn = 10;
                var topicTocColumns = 2;
                if(sideToc.length) {
                    topicContentColumn = 7;
                    if(sideToc.hasClass("d-md-none")) {
                        topicContentColumn = 10;    
                    }
                }
                
                // Check page toc is displayed to the user.
                if(pageToc.hasClass("d-lg-block")) {
                    $(this).addClass("clicked");
                    $(this).attr('aria-expanded', false);
                    pageToc.removeClass("d-lg-block");
                    pageToc.addClass("d-lg-none");
                    
                    var topicContentParent = $('.wh_topic_content').parent();
                    if (topicContentParent !== undefined) {
                        topicContentParent.removeClass(`col-lg-${topicContentColumn}`);
                        topicContentParent.addClass(`col-lg-${topicContentColumn + topicTocColumns}`);
                        topicContentParent.addClass("closed-page-toc");
                    }
                 } else {
                    $(this).removeClass("clicked");
                    $(this).attr('aria-expanded', true);
                    pageToc.removeClass("d-lg-none");
                    pageToc.addClass("d-lg-block");
                    
                    var topicContentParent = $('.wh_topic_content').parent();
                    if (topicContentParent !== undefined) {
                        topicContentParent.removeClass(`col-lg-${topicContentColumn + topicTocColumns}`);
                        topicContentParent.removeClass("closed-page-toc");
                        topicContentParent.addClass(`col-lg-${topicContentColumn}`);
                    }
                    
                    var tocWidth =  parseInt(pageToc.outerWidth()) - parseInt(pageToc.css("padding-left")) - parseInt(pageToc.css("padding-right"));
                    $("#wh_topic_toc_content").css("width", tocWidth);
                 }
                 
                 $(this).css('right', Math.round($("#wh_topic_toc").outerWidth()) * (-1) + 5);
            }
        });

        // WH-2482 Handler for the button that closes the publication toc.
        $('#wh_close_publication_toc_button').click(function () {
                closePublicationToc(sideToc, pageToc);
        });
        
        $('#wh_toc_button').click(function () {
                closePublicationToc(sideToc, pageToc);
        });
        
        // WH-1518: Hide the Breadcrumb tooltip if it is empty.
        var breadcrumb = $('.wh_breadcrumb');
        var breadcrumbShortDesc = breadcrumb.find('.topicref .wh-tooltip .shortdesc:empty');
        if (breadcrumbShortDesc.length > 0) {
            var tooltip = breadcrumbShortDesc.closest('.wh-tooltip');
            tooltip.remove();
        }

        var $allAccordionHeaders = $(".wh_main_page_toc .wh_main_page_toc_accordion_header");
        var $allAccordionButtons = $(".wh_main_page_toc .wh_main_page_toc_accordion_header .header-button");

        $allAccordionHeaders.click(function(event) {
            $headerButton = $(this).find('.header-button');
            if ($(this).hasClass('expanded')) {
                $(this).removeClass("expanded");
                $headerButton.attr('aria-expanded', 'false');
            } else {
                $allAccordionHeaders.removeClass("expanded");
                $(this).addClass("expanded");
                $allAccordionButtons.attr('aria-expanded', 'false');
                $headerButton.attr('aria-expanded', 'true');
            }
            event.stopImmediatePropagation();
            return false;

        });
        /* Toggle expand/collapse on enter and space */
        $allAccordionButtons.keypress(function( event ) {
            // Enter & Spacebar events
            if ( event.which === 13 || event.which === 32) {
                event.preventDefault();
                var $parentHeader = $(this).closest('.wh_main_page_toc_accordion_header');
                if ($parentHeader.hasClass('expanded')) {
                    $parentHeader.removeClass("expanded");
                    $(this).attr('aria-expanded', 'false');
                } else {
                    $allAccordionHeaders.removeClass("expanded");
                    $parentHeader.addClass("expanded");
                    $allAccordionButtons.attr('aria-expanded', 'false');
                    $(this).attr('aria-expanded', 'true');
                }
            }
            return false;
        });

        $(".wh_main_page_toc a").click(function(event) {
            event.stopImmediatePropagation();
        });

        highlightSearchTerm();

        

        /**
         * Check to see if the window is top if not then display button
         */
        $(window).scroll(function(){
            if ($(this).scrollTop() > 5) {
                $('#go2top').fadeIn('fast');
            } else {
                $('#go2top').fadeOut('fast');
            }
        });

        /**
         * Click event to scroll to top
         */
        $('#go2top').click(function(){
            $('html, body').animate({scrollTop : 0},800);

            return false;
        });
    });


/* *
 * @description Computes the position for the elements that are required to position the publication
 * and topic toc.
 */
function computeStickyElementsPositions() {
    var searchHeight = $('.wh_search_input').outerHeight(true);
    var breadcrumbHeight = $(".wh_tools").parent().outerHeight();
    var headerHeight = $(".wh_header").outerHeight();
    var visibleSearchHeight = 0;
    var topOffset = 0;
    var visibleAreaHeight = 0;
    var buttonOffset = 0;
    
    if(options.getBoolean("webhelp.enable.sticky.header")) {
        buttonOffset = searchHeight;
        if ($(window).scrollTop() > searchHeight) {
            visibleSearchHeight = 0;
        } else {
            visibleSearchHeight = searchHeight - $(window).scrollTop();
        }
        topOffset = breadcrumbHeight + headerHeight + visibleSearchHeight;
        visibleAreaHeight = parseInt($(window).height()) - topOffset;
	} else {
        buttonOffset = breadcrumbHeight + headerHeight + searchHeight - DEFAULT_MARGIN_STICKY_HEADER_DISABLED;
	    var visibleHeader = breadcrumbHeight + headerHeight + searchHeight;
	    if($(window).scrollTop() > visibleHeader) {
	        visibleHeader = DEFAULT_MARGIN_STICKY_HEADER_DISABLED;
	    } else {
	        visibleHeader = visibleHeader - $(window).scrollTop();
	    }
	    topOffset = visibleHeader;
	    visibleAreaHeight = parseInt($(window).height()) - topOffset;
	}
	
	return {
	    topOffset: topOffset,
	    visibleAreaHeight: visibleAreaHeight,
        buttonOffset: buttonOffset
	}
}

/* *
 * @description Toggles the expand/collapse for the publication toc.
 */
function closePublicationToc(sideToc, pageToc) {
	// Check publication toc is in DOM.
    if(sideToc.length) {
        var topicContentColumn = 9;
        var publicationTocColumns = 3;
        if(pageToc.length) {
            topicContentColumn = 7;
            if(pageToc.hasClass("d-lg-none")) {
                topicContentColumn = 9;    
            }
        }
        
        // Check publication toc is displayed to the user.
        if(sideToc.hasClass("d-md-block") && sideToc.is(':visible')) {
            $('#wh_close_publication_toc_button').attr('aria-expanded', false);
            $('#wh_toc_button').attr('aria-expanded', false);
            $('#wh_close_publication_toc_button').addClass("clicked");
            sideToc.removeClass(`col-lg-${publicationTocColumns} col-md-${publicationTocColumns}`);
            sideToc.removeClass("d-block");
            sideToc.removeClass("d-md-block");
            sideToc.addClass("d-none");
            sideToc.addClass("d-md-none");
            
            var topicContentParent = $('.wh_topic_content').parent();
            if (topicContentParent !== undefined) {
                topicContentParent.removeClass(`col-lg-${topicContentColumn} col-md-9`);
                topicContentParent.addClass(`col-lg-${topicContentColumn + publicationTocColumns} col-md-12`);
                topicContentParent.addClass("closed-publication-toc");
            }
         } else {
            $('#wh_close_publication_toc_button').attr('aria-expanded', true);
            $('#wh_toc_button').attr('aria-expanded', true);
            $('#wh_close_publication_toc_button').removeClass("clicked");
            sideToc.addClass(`col-lg-${publicationTocColumns} col-md-${publicationTocColumns}`);
            sideToc.removeClass("d-none");
            sideToc.removeClass("d-md-none");
            sideToc.addClass("d-block");
            sideToc.addClass("d-md-block");
            
            var topicContentParent = $('.wh_topic_content').parent();
            if (topicContentParent !== undefined) {
                topicContentParent.removeClass(`col-lg-${topicContentColumn + publicationTocColumns} col-md-12`);
                topicContentParent.removeClass("closed-publication-toc");
                topicContentParent.addClass(`col-lg-${topicContentColumn} col-md-9`);
            }
            
            var tocWidth = parseInt(sideToc.outerWidth()) - parseInt(sideToc.css("padding-left")) - parseInt(sideToc.css("padding-right"));
            $("#wh_publication_toc_content").css("width", tocWidth);
         }
         
         $('#wh_close_publication_toc_button').css('left', $("#wh_publication_toc").outerWidth() * (-1) + 5);
    }
}

/**
 * @description Display the active topic in publication toc.
 */
function displayActiveTopicInPublicationToc() {
    var $sideToc = $(".wh_publication_toc");
    var $slideSection = $('#wh_topic_body');
    if ($sideToc.length > 0 && $slideSection.length > 0) {
        var sideTocTopPos = $(".wh_publication_toc").offset().top;
        var sideTocBottomPos = sideTocTopPos + parseInt($(".wh_publication_toc").outerHeight());
        var activeElementPos = $('.wh_publication_toc .active > .topicref a').offset().top;
        // Check if the selected topic is visibile in the top 80% of the publication toc. 
        if(activeElementPos > 0.8 * sideTocBottomPos) {
            var sideTocMiddlePos = (sideTocTopPos + sideTocBottomPos) / 2;
            $(".wh_publication_toc").animate({scrollTop: activeElementPos - sideTocMiddlePos}, 0);
        }
    }
}

/**
 * @description Handle the vertical position of the side toc
 */
function handlePublicationTocPosition(scrollPosition) {
    var scrollPosition = scrollPosition !== undefined ? scrollPosition : 0;
    var $publicationToc = $(".wh_publication_toc");
    var $navPublicationToc = $("#wh_publication_toc");
    var $topicBody = $('#wh_topic_body');
    var $publicationTocContent = $("#wh_publication_toc_content");

    
    if ($publicationToc.length > 0 && $topicBody.length > 0 && options.getBoolean("webhelp.enable.sticky.publication.toc")) {
        var positions = computeStickyElementsPositions();
        var topOffset = positions.topOffset;
        var visibleAreaHeight = positions.visibleAreaHeight;
        var buttonOffset = positions.buttonOffset;

        var tocWidth = parseInt($navPublicationToc.outerWidth()) - parseInt($navPublicationToc.css("padding-left")) - parseInt($navPublicationToc.css("padding-right"));
    
        if(parseInt($(window).width()) > 767) {
            $publicationTocContent.css("top", topOffset + "px").css("width", tocWidth + "px").css("position", "fixed").css("z-index", "997").css("display", "flex").css("flex-direction", "column");
            $publicationToc.css("overflow-y", "auto").css("overflow-x", "hidden");

            // Adjust publication toc height when the footer apears in the viewport.
            var footerPosition = $(".wh_footer")[0].getBoundingClientRect().top;
            if(visibleAreaHeight + topOffset > footerPosition) {
                $publicationTocContent.css("max-height", visibleAreaHeight - ($(window).height() - footerPosition) - 30);
            } else {
                $publicationTocContent.css("max-height", visibleAreaHeight - 30);
            }

            // Find the position for the close publication toc button.
            if($(window).scrollTop() > buttonOffset) {
                $('#wh_close_publication_toc_button').css('top', $(window).scrollTop() - buttonOffset - 5);
            } else {
                $('#wh_close_publication_toc_button').css('top', '-5px');
            }
            $('#wh_close_publication_toc_button').css('left', $navPublicationToc.outerWidth() * (-1) + 5);  
        } else {
            $publicationTocContent.removeAttr('style');
            $publicationToc.removeAttr('style');
        }
    } else {
        $('#wh_close_publication_toc_button').css('top', '-5px');
        $('#wh_close_publication_toc_button').css('left', $navPublicationToc.outerWidth() * (-1) + 5); 
    }

	return $(window).scrollTop();
}

/**
 * @description Highlight the current node in the page toc section on page scroll or clicking on Topic TOC items 
 */
function pageTocHighlightNode(scrollPosition) {
    var scrollPosition = scrollPosition !== undefined ? Math.round(scrollPosition) : 0;
    
    var searchHeight = $('.wh_search_input').outerHeight(true);

    var scrollMarginTop = $(".wh_tools").parent().outerHeight() + $(".wh_header").outerHeight();
    $('.wh_topic_content .title').parent().css("scroll-margin-top", scrollMarginTop);

    var topOffset = 33;
    scrollPosition += scrollMarginTop;


    var hash = location.hash != undefined ? location.hash : "";
    var hashOffTop = $(hash).offset() != undefined ? $(hash).offset().top : 0;
    var elemHashTop =  hash != "" ? Math.round(hashOffTop) : 0;
    if( hash.substr(1) != '' && elemHashTop >= scrollPosition && (elemHashTop <= (scrollPosition + topOffset)) ){
        
        $('#wh_topic_toc a').removeClass('current_node');
        $('#wh_topic_toc a[data-tocid = "'+ hash.substr(1) + '"]').addClass('current_node');
    } else {
        $.each( $('.wh_topic_content .title'), function (e) {
            var currentId = $(this).parent().attr('id');
            var elemTop = Math.round($(this).offset().top);
    
            if( elemTop >= scrollPosition && (elemTop <= (scrollPosition + topOffset)) ){
                
                $('#wh_topic_toc a').removeClass('current_node');
                $('#wh_topic_toc a[data-tocid = "'+ currentId + '"]').addClass('current_node');
            }  
        });
    }
    return $(window).scrollTop();
}



/**
 * @description Handle the vertical position of the page toc
 */
function handleTopicTocPosition(scrollPosition) {
    scrollPosition = scrollPosition !== undefined ? scrollPosition : 0;
    var $navTopicToc = $("#wh_topic_toc");
    var $topicToc = $(".wh_topic_toc");
    var $topicTocContent = $("#wh_topic_toc_content");
    
    if ($topicToc.length > 0 && options.getBoolean("webhelp.enable.sticky.topic.toc")) {
        var positions = computeStickyElementsPositions();
        var topOffset = positions.topOffset;
        var visibleAreaHeight = positions.visibleAreaHeight;
        var buttonOffset = positions.buttonOffset;

        pageTocHighlightNode(scrollPosition);
        
        var tocHeight = parseInt($topicToc.height()) + parseInt($topicToc.css("padding-top")) + parseInt($topicToc.css("padding-bottom")) + parseInt($topicToc.css("margin-top")) + parseInt($topicToc.css("margin-bottom"));
        var tocWidth =  parseInt($navTopicToc.outerWidth()) - parseInt($navTopicToc.css("padding-left")) - parseInt($navTopicToc.css("padding-right"));

        if (tocHeight < visibleAreaHeight && parseInt($(window).width()) > 767) {
            $topicTocContent.css("top", topOffset + "px").css("position", "fixed").css("width", tocWidth + "px");

            // Find the position for the close publication toc button.
            if($(window).scrollTop() > buttonOffset) {
                $('#wh_close_topic_toc_button').css('top', $(window).scrollTop() - buttonOffset - 5);
            } else {
                $('#wh_close_topic_toc_button').css('top', '-5px');
            }
            $('#wh_close_topic_toc_button').css('right', Math.round($navTopicToc.outerWidth()) * (-1) + 5);
        } else {
            $topicTocContent.removeAttr('style');
            $('#wh_close_topic_toc_button').css('top', '-5px');
            $('#wh_close_topic_toc_button').css('right', Math.round($navTopicToc.outerWidth()) * (-1) + 5);
        }
    } else {
        $('#wh_close_topic_toc_button').css('top', '-5px');
        $('#wh_close_topic_toc_button').css('right', Math.round($navTopicToc.outerWidth()) * (-1) + 5);
    }
}

    /**
     * @description Highlight searched words
     */
    function highlightSearchTerm() {
        util.debug("highlightSearchTerm()");
        if (highlighted) {
            return;
        }
        try {
            var $body = $('.wh_topic_content');
            var $relatedLinks = $('.wh_related_links');
            var $childLinks = $('.wh_child_links');

            // Test if highlighter library is available
            if (typeof $body.removeHighlight != 'undefined') {
                $body.removeHighlight();
                $relatedLinks.removeHighlight();

                var hlParameter = util.getParameter('hl');
                if (hlParameter != undefined) {
                    var jsonString = decodeURIComponent(String(hlParameter));
                    util.debug("jsonString: ", jsonString);
                    if (jsonString !== undefined && jsonString != "") {
                        var words = jsonString.split(',');
                        util.debug("words: ", words);
                        for (var i = 0; i < words.length; i++) {
                            util.debug('highlight(' + words[i] + ');');
                            $body.highlight(words[i]);
                            $relatedLinks.highlight(words[i]);
                            $childLinks.highlight(words[i]);
                        }
                    }
                }
            } else {
                // JQuery highlights library is not loaded
            }
        }
        catch (e) {
            util.debug (e);
        }
        highlighted = true;
    }

    /*
     * Hide the highlight of the search results
     */
    $('.wh_hide_highlight').click(function(){
        $('.highlight').addClass('wh-h');
        $('.wh-h').toggleClass('highlight');
        $(this).toggleClass('hl-close');
    });

    /*
     * Show the highlight button only if 'hl' parameter is found
     */
    if( util.getParameter('hl')!= undefined ){
        $('.wh_hide_highlight').show();
    }

});
