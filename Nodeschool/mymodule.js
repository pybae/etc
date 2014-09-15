var fs = require("fs");
var path = require("path");

module.exports = function (pathName, filter, callback) {
  fs.readdir(pathName, function (err, list) {
    var newList = [];

    if (err)
      return callback(err);
  
    list.forEach(function (entry) {
      if (path.extname(entry) === "." + filter) {
        newList.push(entry);
      }
    })

    callback(null, newList);
  })
}

