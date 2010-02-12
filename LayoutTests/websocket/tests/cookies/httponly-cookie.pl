#!/usr/bin/perl -wT
use strict;

print "Content-Type: text/html\r\n";
print "Set-Cookie: WK-websocket-test=1\r\n";
print "Set-Cookie: WK-websocket-test-httponly=1; HttpOnly\r\n";
print "\r\n";
print <<HTML
<html>
<head>
<script src="../../../fast/js/resources/js-test-pre.js"></script>
<script src="../../../fast/js/resources/js-test-post-function.js"></script>
</head>
<body>
<p>Test WebSocket sends HttpOnly cookies.</p>
<p>On success, you will see a series of "PASS" messages, followed by "TEST COMPLETE".</p>
<div id="console"></div>
<script>
if (window.layoutTestController) {
    layoutTestController.dumpAsText();
    layoutTestController.waitUntilDone();
}

var cookie;

function endTest()
{
    shouldBe("cookie", '"WK-websocket-test=1; WK-websocket-test-httponly=1"');
    isSuccessfullyParsed();
    if (window.layoutTestController)
       layoutTestController.notifyDone();
}

var ws = new WebSocket("ws://127.0.0.1:8880/websocket/tests/cookies/echo-cookie");
ws.onopen = function() {
    debug("WebSocket open");
};
ws.onmessage = function(evt) {
    cookie = evt.data;
    ws.close();
};
ws.onclose = function() {
    debug("WebSocket closed");
    endTest();
};

var successfullyParsed = true;
</script>
</body>
</html>
HTML
