node-pledge
===========

Bindings for for OpenBSD's [pledge(2)](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/pledge.2?query=pledge)

# What?

`pledge(2)` allows process to ratchet down the privlidges it requires to run, if it attempts to access
a privlidge it has pledged to not use, it will be killed by the kernel.

# Example Usage

```
var http = require('http');
var pledge = require('pledge');

pledge.init("stdio rpath wpath ioctl");

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
Killed
```

Line from `dmesg(8)`:

```
node(9940): syscall 8
```

# This is just an expirement!
