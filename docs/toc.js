// Functions for toc
if (window.parent.location.protocol != 'file:') {
    document.addEventListener('click', function(e) {
        if (e.target && e.target.nodeName == "A" && e.target.nodeType == 1) {
            e.preventDefault();
            e.stopPropagation();

            var origUrl = window.parent.location.href.substr(0, window.parent.location.href.indexOf("?"));

            if (origUrl.length === 0) {
                origUrl = window.parent.location.href;
            }

            var href= e.target.getAttribute("href");
            var parts = href.split("#");

            var url = parts[0].replace('.html','');
            if (parts.length == 2) {
                url += "#" + parts[1];
            }
            window.parent.location.href = origUrl + "?" + url;

            return false;
        }
    });
}

function exp(id) {
    var myElt = document.getElementById('p' + id);
    if (myElt) {
        // check current display state
        if (myElt.src.slice(myElt.src.lastIndexOf('/') + 1) == 'minus.png') {
            collapse(id);
        } else {
            expand(id);
        }
    }
}

function expand(id) {
    var myDoc = window.parent.navigationwin.document;
    var myElt = myDoc.getElementById('s' + id);
    if (myElt) {
        with (myElt) {
            className = 'x';
            style.display = '';
        }
        var iconEl = myDoc.getElementById('p' + id);
        if (iconEl) {
            iconEl.src = 'minus.png';
            myDoc.getElementById('b' + id).src = 'book.png';
        }
    }
}

function collapse(id) {
    var myElt = document.getElementById('s' + id);
    if (myElt) {
        with (myElt) {
            className = 'x';
            style.display = 'none';
        }
        document.getElementById('p' + id).src = 'plus.png';
        document.getElementById('b' + id).src = 'book.png';
    }
}


var _highlightedEl;
function highlight(myElt) {
    if (_highlightedEl) {
        _highlightedEl.parentElement.setAttribute("class", "tocItem");
    }
    if (myElt) {
        myElt.hideFocus = true;

        if (window_focus) {
            myElt.parentElement.setAttribute("class", "tocItem highlighted");
        } else {
            myElt.parentElement.setAttribute("class", "tocItem highlighted lostFocus");
        }
        _highlightedEl = myElt;
        var parent = myElt.parentElement;
        if (parent) {
            expand(parent.parentElement.getAttribute("id").substring(1));
            // Go all the way up
            var nextParent = parent.parentElement;
            while (nextParent) {
                var id = nextParent.getAttribute("id");
                if (id) {
                    expand(id.substring(1));
                    nextParent = nextParent.parentElement;
                } else {
                    nextParent = null;
                }
            }
        }
        //setTimeout(addEventListenerContentWindow, 200);
        window.parent.navigationwin.scrollTo(myElt.offsetLeft - 48, myElt.offsetTop);
    }
}

function loadTOC() {
    // check current page displayed in TOC window.  If not toc.htm, load it.
    if (!isTOCLoaded()) {
        window.parent.navigationwin.location.href = 'toc.html';
    }
}

function isTOCLoaded() {
    // return true, if toc.htm is loaded in TOC window.
    if (window.parent.toc) {
        var myPath = window.parent.navigationwin.location.pathname;
        var myFile = myPath.substr(myPath.length - 7);

        if (myFile == 'toc.html') {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

function selectOpenedTopic() {
    setTimeout(function () {
        // Check which topic is opened
        try {
            var search = "";
            if (window.parent.location.href.indexOf("?") > -1) {
                search = window.parent.location.href.substr(window.parent.location.href.indexOf("?")).replace('?','');
                if (search.indexOf('#') > -1) {
                    search = search.split('#')[1];
                }
            }

            var currentTopic = window.parent.frames.contentwin.document.head.querySelector("meta[name='DC.identifier']");
            if (currentTopic) {
                currentTopic = currentTopic.getAttribute('content');
            }
            
            var file = FileSequence[0];
            if (currentTopic && currentTopic.indexOf(search) == -1) {
                file = findInFileSequence(search);
            } else {
                file = findInFileSequence(currentTopic);
            }

            var navItem = window.parent.navigationwin.document.querySelector("[href='" + file + "']");
            if (!navItem) {
                if (file && file.indexOf('#') > -1) {
                    var firstPart = file.split('#')[0];
                    navItem = window.parent.navigationwin.document.querySelector("[href='" + firstPart + "']");
                }
            }
            
            if (!navItem) {
                var parts = window.parent.location.href.substr(window.parent.location.href.indexOf("?")).replace('?','').split('#');
                var fullUrl = parts[0] + ".html" + "#" + parts[1];
                navItem = window.parent.navigationwin.document.querySelector("[href='" + fullUrl + "']");
            }


            // Add support for bookmap
            var param = window.parent.location.href.substr(window.parent.location.href.indexOf("?") + 1);		
            var param2 = param.split("#");  
            if (param2[1]){  
                locString = param2[0] + ".html#" + param2[1];        
                navItem = window.parent.navigationwin.document.querySelector("[href='" + locString + "']");
            } 

            if (navItem) {
                highlight(navItem);
            } else {
                // highlight first item
                var firstItem = window.parent.navigationwin.document.querySelector("a[target='contentwin']");
                if (firstItem) {
                    highlight(firstItem);
                }
            }
        } catch (e) {}
        //addEventListenerContentWindow();
    }, 1000);
}


setInterval(function(){
    var hasEvent = !!window.parent.contentwin.onclick;
    if (!hasEvent) {
        selectOpenedTopic();

        var openTopic = function (event) {
            selectOpenedTopic();
        };
        window.parent.contentwin.onclick =  openTopic;
    }
}, 300);


function addEventListenerContentWindow() {
    try {
        var openTopic = function (event) {
            selectOpenedTopic();
        };
        // Window was refreshed so apply bindings again
        if (window.parent.contentwin.addEventListener) {
            window.parent.contentwin.removeEventListener("click", openTopic, false);
            window.parent.contentwin.addEventListener("click", openTopic, false);
        } else {
            window.parent.contentwin.document.detachEvent("onclick", openTopic);
            window.parent.contentwin.document.attachEvent("onclick", openTopic);
        }
    } catch (e) {
        if (console.log) {
            console.log(e);
        }
    }
}

// Add endsWidth to string
String.prototype.endsWith = function (suffix) {
    return this.indexOf(suffix, this.length - suffix.length) !== -1;
};

// Add event handlers to keep state of the selected topic
if (window.parent.headerwin.addEventListener) {
    window.parent.headerwin.addEventListener("click", function (event) {
        selectOpenedTopic();
    }, false);
} else {
    // For older browsers like IE8
    window.parent.headerwin.document.attachEvent("onclick", function () {
        selectOpenedTopic();
    });
    addEventListenerContentWindow();
}
if (window.parent.navigationwin.location.href.toLowerCase().endsWith("toc.html")) {
    selectOpenedTopic();
}

// Unfocused selection state for the tree items
var window_focus = false;
setTimeout(function () {

    if (window.addEventListener) {
        window.addEventListener("focus", function () {
            window_focus = true;
        });
        window.addEventListener("click", function () {
            window_focus = true;
        });
        window.addEventListener("blur", function () {
            window_focus = false;
        });
    } else {
        // No unfocused state for older browsers
        window_focus = true;
    }

    setInterval(function () {
        if (window_focus == false) {
            var currentItem = window.document.querySelector("div[class='tocItem highlighted']");
            if (currentItem) {
                currentItem.setAttribute("class", "tocItem highlighted lostFocus");
            }
        }
    }, 1000);

}, 1000);

function findInFileSequence(guid)
{
    if (Array.isArray(FileSequence)) {
        return FileSequence.filter(function(file) {
            return file.indexOf(guid) > -1;
        }).shift();
    }
    return false;
}
