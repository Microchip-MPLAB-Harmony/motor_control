function LoadDocument(frameId)
{
	var param = location.href.substr(location.href.indexOf("?") + 1);
	var newDoc = "start.html?" + param;
	var f = document.getElementById(frameId);
	f.src = newDoc;
}
