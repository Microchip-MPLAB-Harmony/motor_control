window.onload = function() {   
    rewriteIframes('low.png');
}

function shouldRewriteIframes() {
     const userAgent = navigator.userAgent || navigator.vendor || window.opera;
    // Check for Android mobile device
    const isAndroidMobile = /android/i.test(userAgent) && /mobile/i.test(userAgent);
    // Check for iPhone or iPod
    const isAppleMobile = /iPhone|iPad|iPod/.test(userAgent) && !window.MSStream;
    return isAndroidMobile || isAppleMobile;
}

function rewriteIframes(phrase) { 
 if (shouldRewriteIframes()) {
  
  // Select all iframe elements
  var iframes = document.querySelectorAll('iframe');

  // Loop through each iframe
  iframes.forEach(function(iframe) {
    // Create a new img element
    var img = document.createElement('img');

    //There are 18 characters on the end of the src we need to clip off and replace with a new value.
    img.src = iframe.src.slice(0, -18) + phrase;
    img.alt = iframe.src.slice(0, -18) + phrase;    
    img.height = iframe.height;
    img.width = iframe.width;

    // Replace the iframe with the img in the DOM
    iframe.parentNode.replaceChild(img, iframe);
  }); 
 
  } 
}