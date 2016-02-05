#!/usr/bin/env node

// Quick example of a pledged node app.
// usage:
// $ echo '{"a":1,"b":3}' | ./pp.js

var data = '', pledge = require('node-pledge');
pledge.init('stdio ioctl rpath tty');

process.stdin.setEncoding('utf8');
process.stdin.on('readable', function() {
    var chunk = process.stdin.read();
    if (chunk !== null) {
	data += chunk;
    }
});

process.stdin.on('end', function() {
    data = JSON.parse(data);
    console.log(JSON.stringify(data, null, 2));
});
