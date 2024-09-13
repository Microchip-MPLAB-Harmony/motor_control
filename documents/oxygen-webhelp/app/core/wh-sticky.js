define(["jquery"], function ($) {
    
    $(document).ready(function () {
      const header = $(".wh_header");
      header.addClass("header-sticky");
      header.css({"top": "0"});
      
      const breadcrumb = $(".wh_tools").parent();
      breadcrumb.addClass("breadcrumb-sticky");
      breadcrumb.css({"top": header.outerHeight()});
      
      const whIndexTerms = $(".wh-letters");
      whIndexTerms.addClass("indexTerms-sticky");
      whIndexTerms.css({"top": header.outerHeight()});
      
      $("html").css({"scroll-padding-top": header.outerHeight() + breadcrumb.outerHeight()});
      
      /* 
       * WH-2778
       * Handle the URL with an anchor and the header is sticky. 
       */
      if(window.location.hash && $(window).scrollTop() > 0) {
        var breadcrumbHeight = breadcrumb.outerHeight(); 
        var headerHeight = header.outerHeight();
        window.scrollBy(0, (breadcrumbHeight + headerHeight) * (-1));
      }

      const targetElement = document.getElementsByClassName("wh_header")[0];
      
      
      const resizeObserver = new ResizeObserver(entries => {
        breadcrumb.css({"top": header.outerHeight()});
        whIndexTerms.css({"top": header.outerHeight()});
        
      });

	  resizeObserver.observe(targetElement);


    });
});