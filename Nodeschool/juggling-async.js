var http = require('http');
var bl = require('bl');

var results = [];
var num_urls = 3;
var count = 0;

function printResults () {
  for (var i = 0; i < results.length; i++) {
    console.log(results[i]);
  }
}

function http_get_wrapper(i) {
  http.get(process.argv[2 + i], function (response) {
    response.pipe(bl(function (err, data) {
      if (err)
        throw err;

      var str = data.toString();
      results[i] = str;
      count++;

      if (count == 3)
        printResults();
    }))
  })
}

for (var i = 0; i < num_urls; i++) {
  http_get_wrapper(i);
}
