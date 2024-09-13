define(["options", "jquery"], function (options, $) {


    var selectors = {
        /* WH-1613 - permalink selector  */
        "permalinks": [
            ".dt[id]",
            ".section[id] .sectiontitle",
            ".title.topictitle2[id]",
            "table[id] .tablecap"
        ]
    };
    
    $(document).ready(function () {
    	/*
         * WH-1613
         * Add the permalink icons
         */
        selectors.permalinks.forEach(
            function (selector) {
                var matchedNodes = $(document).find(selector);
                // Add the element for the permalink action
                matchedNodes.append("<span class='permalink'/>");
            }
        );
        
        /*
         * WH-1613
         * Permalink action
         * */
        $('span.permalink').click(function (e) {
            var id = $(this).closest('[id]').attr('id');
            var hash = '#' + id;
            e.preventDefault();
            history.replaceState({}, '', hash);
			if(options.getBoolean("webhelp.enable.sticky.header")) {
				var toolsHeight = $(".wh_tools").parent().outerHeight(); 
            	var headerHeight = $(".wh_header").outerHeight();
            
            	$('html, body').animate({scrollTop: $("[id='" + id + "']").offset().top - toolsHeight - headerHeight}, 1000);
			} else {
				$('html, body').animate({scrollTop: $("[id='" + id + "']").offset().top}, 1000);
			}
            
        });
    });
});