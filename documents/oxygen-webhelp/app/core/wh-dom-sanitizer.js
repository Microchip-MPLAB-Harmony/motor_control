define(["dompurify"], function(DOMPurify) {
    
    /* *
     * Appends the given source HTML node to the given destionation HTML node.
     * 
     * @param $source The source HTML node to append.
     * @param $dest The destination HTML node.
     */
    function appendHtmlNode($source, $dest) {
        var sanitizedSource = DOMPurify.sanitize($source[0]);
        $dest.append(sanitizedSource);
    }
    
    /* *
     * Appends the given source HTML element to the body
     * 
     * @source The souce HTML element to append.
     * 
     * @returns the appended element.
     */
    function appendElementNodeToBody(source) {
        var sanitizedSource = DOMPurify.sanitize(source, {RETURN_DOM: true, RETURN_DOM_IMPORT: true});
        var appendedElement = document.body.appendChild(sanitizedSource.firstChild);
        return appendedElement;
    }
    
    /* *
     * Sanitizes the given string.
     */
    function sanitize(str) {
        return DOMPurify.sanitize(str, {ALLOWED_TAGS: []})
    }
    
    return {
        appendHtmlNode: appendHtmlNode,
        appendElementNodeToBody: appendElementNodeToBody,
        sanitize: sanitize
    }
})