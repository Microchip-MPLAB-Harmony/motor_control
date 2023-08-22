define(['util', 'jquery', 'options', 'jquery.highlight'], function(util, $, options) {
    var isTouchEnabled = false;
    try {
        if (document.createEvent("TouchEvent")) {
            isTouchEnabled = true;
        }
    } catch (e) {
        util.debug(e);
    }
	
	/**
     * Open the link from top_menu when the current group is expanded.
     *
     * Apply the events also on the dynamically generated elements.
     */

    $(document).on('click', ".wh_top_menu li", function (event) {
        $(".wh_top_menu li").removeClass('active');
        $(this).addClass('active');
        $(this).parents('li').addClass('active');

        event.stopImmediatePropagation();
    });
    
    $(document).on({
        // Hide menu on click outside its bounds
        'click': function(event){
            var container = $(".wh_top_menu");
            if (!container.is(event.target) &&            // If the target of the click isn't the container...
                container.has(event.target).length === 0) {// ... nor a descendant of the container
                // Click outside -> hide the menu
                $(".wh_top_menu li.active").removeClass('active');
            }
        },
        // Hide menu when ESC is pressed
        'keydown': function (e) {
          if (e.which === 27) {
            $(".wh_top_menu li.active").removeClass('active');
          }
        }
    });
    
    var isMenuActivatedOnClick = options.getBoolean("webhelp.top.menu.activated.on.click");
    $(document).on('click', '.wh_top_menu a', function (event) {
        var pointerType;
        if (typeof event.pointerType !== "undefined") {
            pointerType = event.pointerType;
        }
        if (isMenuActivatedOnClick || $(window).width() < 767 || isTouchEnabled || pointerType == "touch") {
            var areaExpanded = $(this).closest('li');
            var isActive = areaExpanded.hasClass('active');
            var hasChildren = areaExpanded.hasClass('has-children');
            if (isActive || !hasChildren) {
                window.location = $(this).attr("href");
                event.preventDefault();
                event.stopImmediatePropagation();
                return false;
            } else {
                event.preventDefault();
            }
        } else {
            return true;
        }
    });
});
