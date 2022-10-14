/* =============================================================================
	 Trisoft CMS Web Help Script v1.0
	 
	 Copyright (c) 2008-2009 SDL Trisoft (http://www.trisoftcms.com)
	
	 Tested on windows with        IE6, IE7, FF2, FF3, Opera 9.62
	 Tested on Linux (ubuntu) with FF3
	 
	 You may only use this script library on web help content 
	 generated using Trisoft CMS
   ========================================================================== */

function ChangeMenu(tabname)
{
	var locString = '';
/*	alert(tabname);*/
	
	switch (tabname.toLowerCase()) {
	   case 'content': 
	   	locString = 'toc.html';
	   	break;
	   case 'index': 
	   	locString = 'indexpage.html';
	   	break;
	   case 'search': 
	   	locString = 'search.html';
	   	break;
	   default: 
	   	locString = '';
	 }
/*	 alert(locString); */
   var win = open(locString,'navigationwin');	 
/*   if (!parent.showNavWin) parent.ToggleNavWin(); */
   
   document.getElementById('content').className= '';
   document.getElementById('index').className= '';
   document.getElementById('search').className= '';
   document.getElementById(tabname.toLowerCase()).className= 'current';
/* change end li elements className value */
   document.getElementById('content-end').className= 'end';
   document.getElementById('index-end').className= 'end';
   document.getElementById('search-end').className= 'end';
   document.getElementById(tabname.toLowerCase()+'-end').className= 'endcurrent';
   
}

function checkUrl(url, cb)
{
	var xhr = new XMLHttpRequest();

	xhr.open('get', url, true);

	xhr.onreadystatechange = checkReadyState;

	function checkReadyState() {
		if (xhr.readyState === 4) {
			
			if ((xhr.status == 200) || (xhr.status == 0)) {
				if (cb) cb(true);
			}
			else {
				if (cb) cb(false);
			}
		}
	}
	xhr.send(null);
}

function showPrevTopic(pos)
{
	var currentlocation = window.parent.contentwin.location.toString();
	var strippedCurrentTopicName = currentlocation.substring(currentlocation.lastIndexOf("/")+1,currentlocation.length);

	var CurrentPos = locateCurrentTopic(strippedCurrentTopicName);
	
	if (pos) {
		CurrentPos = pos;
	}
	
	if (CurrentPos > -1)
	{
	  if (CurrentPos>0)
		{
		  NewPos = CurrentPos-1;
	    var locString = '';	
		  locString = FileSequence[NewPos];
		  
		if (locString.indexOf("atmel.register.table") > -1) {
			showPrevTopic(CurrentPos-1);
			return;
		}
		
		checkUrl(locString, function(exists){
			if (exists) {
				var win = open(locString,'contentwin');		 
			} else {
				showPrevTopic(CurrentPos-1);
			}
		});
		
	  }
	  else
		{
		  alert('This is the first topic of your content.');
    }

   }

}

function showNextTopic(pos) 
{
	
	var currentlocation = window.parent.contentwin.location.toString();
	var strippedCurrentTopicName = currentlocation.substring(currentlocation.lastIndexOf("/")+1,currentlocation.length);

	var CurrentPos = locateCurrentTopic(strippedCurrentTopicName);
	
	if (pos) {
		CurrentPos = pos;
	}
	
	if (CurrentPos > -1)
	{
	  if ((FileSequence.length-1)>CurrentPos)
		{
		  NewPos = CurrentPos+1;
	    var locString = '';	
		  locString = FileSequence[NewPos];
		  
		if (locString.indexOf("atmel.register.table") > -1) {
			showNextTopic(CurrentPos+1);
			return;
		}
		
		checkUrl(locString, function(exists){
			if (exists) {
				var win = open(locString,'contentwin');		 
			} else {
				showNextTopic(CurrentPos+1);
			}
		});
		   
	  }
	  else
		{
			alert('This is the last topic of your content.');
    }
   }
}

function locateCurrentTopic(curTopic)
{
	var locationFound = -1;
	for (var arrayCounter=0; arrayCounter<FileSequence.length; arrayCounter++)
	{
		if (FileSequence[arrayCounter] == curTopic)
		{
			locationFound = arrayCounter;
			break;
		}
	}
	return locationFound;
}

function printTopic()
{
	if (window.print) 
	{
		window.parent.contentwin.focus();
		window.parent.contentwin.print();
	}
}

function firstTopic()
{
	var locString = FileSequence[0];
	var param = location.href.substr(location.href.indexOf("?") + 1);		
    var param2 = param.split("#");  
    //If GUID appears at the start of the string, the first entry
    //will be the zero-length space in front of GUID, so we start
    //by testing for a third value (which will be there if it is a compound address)
    //and failing that we test for a 2nd value, which would be the first GUID value
    //After that we give up and use the value drawn from the FileSequence array.

	var url = param2[0].length > 0 ? param2[0] : "";
	if (param2.length == 2){  
        locString = url + ".html#" + param2[1];        
	}  else if (param2[0]){   
		try {
			if (window.parent.location.search.replace("?","").length  > 0 ) {
				var file = findInFileSequence(url);
				locString = file;
			}
		} catch (e) {
			if (window.location.search.replace("?","").length > 0) {
				var file = findInFileSequence(url);
				locString = file;
			}
		}
    } 

	var win = open(locString,'contentwin');		
}

function findInFileSequence(guid)
{
    if (Array.isArray(FileSequence)) {
        return FileSequence.filter(function(file) {
            return file.indexOf(guid) > -1;
        }).shift();
    }
    return false;
}