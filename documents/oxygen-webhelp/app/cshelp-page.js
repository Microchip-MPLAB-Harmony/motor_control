/**
 * Load the libraries for the Context Sensitive Help page.
 */
define(["require", "config"], function() {
    require(['options'], function(options){
        const jsModules = [
           'context-help'
        ];
        require(jsModules);
    });
});