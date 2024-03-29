node-pledge
===========

Bindings for for OpenBSD's [pledge(2)](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/pledge.2?query=pledge)

# What?

`pledge(2)` allows a process to ratchet down the privileges it requires to run, if it attempts to access
a privilege it has pledged to not use, it will be killed by the kernel.

# Example Usage

Install via npm:

```
npm install --save node-pledge
```

```JavaScript
var http = require('http');
var pledge = require('node-pledge');

pledge.init("stdio rpath wpath prot_exec");

console.log("stuff");

// try to do something with http (will cause the kernel to kill node)
http.get("http://www.google.com/", function(res) {
  console.log(res);
}).on('error', function(e) {
  console.log(e);
});
```

Output:

```
node stuff.js
stuff
Abort trap (core dumped) 
```

Line from `dmesg(8)`:

```
node(24353): sysctl 6: 4 17 0 0 3 0
node(24353): syscall 202 ""
```

# This is an expirement!

Use at your own risk! It will *ONLY* work on OpenBSD!
