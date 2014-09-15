var fs = require("fs");

var callback = function (err, data) {
  console.log(data.split('\n').length - 1);
}

fs.readFile(process.argv[2], 'utf8', callback);
