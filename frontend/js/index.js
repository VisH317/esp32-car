var url = `ws://${window.location.hostname}/ws`
var websocket

function onLoad() {
    initializeSocket()
}

function initializeSocket() {
    websocket = new WebSocket(url)
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}
function onOpen(event) {
    console.log('Starting connection to server..');
}
function onClose(event) {
    console.log('Closing connection to server..');
    setTimeout(initializeSocket, 2000);
}
function onMessage(event) {
    console.log("WebSocket message received:", event)
}

function sendMessage(message) {
    websocket.send(message);
}

buttons = ["forward", "right", "left", "backward", "stop"]

buttons.foreach(b => document.getElementById(b).addEventListener("click", e => sendMessage(b)))