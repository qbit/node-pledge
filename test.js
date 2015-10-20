var http = require('http');
var pledge = require('./build/Release/pledge');

pledge.init("stdio rpath wpath ioctl");
console.log("stuff");

http.get("http://www.google.com/index.html", function(res) {
  console.log("Got response: " + res.statusCode);
}).on('error', function(e) {
  console.log("Got error: " + e.message);
});
