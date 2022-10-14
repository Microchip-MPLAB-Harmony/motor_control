/* =============================================================================
	 Trisoft CMS Web Help Script v1.0
	
	 Copyright (c) 2008-2009 SDL Trisoft (http://www.trisoftcms.com)
	
	 Tested on windows with        IE6, IE7, FF2, FF3, Opera 9.62
	 Tested on Linux (ubuntu) with FF3
	 
	 You may only use this script library on web help content 
	 generated using Trisoft CMS
   ========================================================================== */
   
var targetsShown = "";

function showTargets(pId)
{
	if (targetsShown != "")
	{
		hideTargets(targetsShown);
	}
	var obj = document.getElementById(pId);
	obj.style.display = "block";
	targetsShown = pId;
}			

function hideTargets(pId)
{
	var obj = document.getElementById(pId);
	obj.style.display = "none";
	targetsShown = "";
}			

function hideAllTargets()
{
	if (targetsShown != "")
	{
		hideTargets(targetsShown);
	}
}	
/* =============================== End Of File =============================== */   