#!/usr/bin/env node
var s = require('semver');
var v = s.gt('v4.0.0', process.version);
if (v) {
  console.log('yes');
} else {
  console.log('no');
}
