// Set up
var serialport = require("serialport");

var express = require('express');
var app = express();
var expressWs = require('express-ws')(app);
var aWss = expressWs.getWss('/');

app.ws('/', function(ws, req) {
  port.on('data', function (data) {
    aWss.clients.forEach(function (client) {
      client.send(data);
    });
  });
});

var port = new serialport("/dev/cu.usbmodem1411", {
  baudRate: 57600,
  parser: serialport.parsers.readline('--')
});

app.listen(8081);