define(["require", "util", "dom-sanitizer"], function (require, util, domSanitizer) {
    $(document).ready(function () {
        // If we have a contextID, we must to redirect to the corresponding topic
        var contextId = util.getParameter('contextId');
        var appname = util.getParameter('appname');

        if (contextId != undefined && contextId != "") {
            require(["context-help-map"], function (helpContext) {
                if (helpContext != undefined) {
                    for (var i = 0; i < helpContext.length; i++) {
                        var ctxt = helpContext[i];
                        if (contextId == ctxt["appid"] && (appname == undefined || appname == ctxt["appname"])) {
                            var path = ctxt["path"];
                            if (path != undefined) {
                                var anchor = decodeURI(window.location.hash);
                                var sanitizedAnchor = domSanitizer.sanitize(anchor);
                                window.location = path + sanitizedAnchor;
                            }
                            break;
                        }
                    }
                }
            });
        }
    });
});