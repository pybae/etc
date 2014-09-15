var fs = require("fs");

var buf = fs.readFileSync(process.argv[2]);

var array = buf.toString().split("\n");

console.log(array.length-1);
