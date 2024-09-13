define(["require", "config"], function() {
    require(['options'], function(options){
        
        const jsModules = [
            'bootstrap',
        ];    
    
        if(options.getBoolean("webhelp.enable.sticky.header")) {
            jsModules.push('wh-sticky');
        }
        if(!options.getBoolean("webhelp.custom.search.engine.enabled")) {
            require(['search'], function() {
                jsModules.push('searchAutocomplete');
                require(jsModules);
            });
        } else {
            require(jsModules);
        }
    });
});