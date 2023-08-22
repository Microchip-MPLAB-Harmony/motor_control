define(['util', 'dom-sanitizer', 'jquery', 'jquery.highlight'], function(util, domSanitizer, $) {		
	$(document).ready(function () {
		/*
         * Codeblock copy to clipboard action
         */
        $('.codeblock').mouseover(function(){
            // WH-1806
            var item = $('<span class="copyTooltip wh-tooltip-container" data-tooltip-position="left"/>');
            if ( $(this).find('.copyTooltip').length == 0 ){
                $(this).prepend(item);

                $('.codeblock .copyTooltip').click(function(){
                    var txt = $(this).closest(".codeblock").text();
                    if(!txt || txt == ''){
                        return;
                    }
                    copyTextToClipboard(txt, $(this));
                });
            }
        });

        $('.codeblock').mouseleave(function(){
            $(this).find('.copyTooltip').remove();
        });

        /**
         * @description Copy the text to the clipboard
         */
        function copyTextToClipboard(text, copyTooltipSpan) {
            var textArea = document.createElement("textarea");
            textArea.style.position = 'fixed';
            textArea.value = text;
            textArea = domSanitizer.appendElementNodeToBody(textArea);
            textArea.select();
            try {
                var successful = document.execCommand('copy');

                // WH-1806
                if (copyTooltipSpan.find('.wh-tooltip').length == 0) {
                    var tooltipContainer = $(
                    '<span>' +
                        '  <span class="wh-tooltip"><p class="wh-tooltip-content">Copied to clipboard</p></span>' +
                        '</span>'
                    );
                    copyTooltipSpan.prepend(tooltipContainer);
                    copyTooltipSpan.mouseleave(function() {
                        tooltipContainer.remove();
                    });
                    setTimeout(function(){ tooltipContainer.remove();}, 3000);
                }
            } catch (err) {
                // Unable to copy
                if (copyTooltipSpan.find('.wh-tooltip').length == 0) {
                    var tooltipContainer = $(
                        '<span>' +
                        '  <span class="wh-tooltip"><p class="wh-tooltip-content">Oops, unable to copy</p></span>' +
                        '</span>'
                    );
                    copyTooltipSpan.mouseleave(function() {
                        tooltipContainer.remove();
                    });
                    copyTooltipSpan.prepend(tooltipContainer);
                    setTimeout(function(){ tooltipContainer.remove(); }, 3000);
                }
                // WH-1806
                //$('.copyTooltip').tooltip({title: 'Oops, unable to copy', trigger: "click"});
                util.debug('Oops, unable to copy codeblock content!', err)
            }
            document.body.removeChild(textArea);
        }
	});	
});