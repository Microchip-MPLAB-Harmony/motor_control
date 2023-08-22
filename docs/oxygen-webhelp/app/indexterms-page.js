/**
 * Load the libraries for the Index Terms page.
 */
define(["require", "config"], function() {
    require(['options'], function(options){
        const jsModules = [
            'polyfill',
	        'menu',
	        'expand',
	        'permalink',
	        'template-module-loader',
	        'top-menu'
        ];
        if(options.getBoolean("webhelp.enable.sticky.header")) {
        	jsModules.push('wh-sticky');
        }
        require(jsModules);
    });
});