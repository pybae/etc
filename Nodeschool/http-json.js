var http = require('http');
var url = require('url');

var server = http.createServer(function (req, res) {
  res.writeHead(200, { 'Content Type': 'application/json' });

  var url_object = url.parse(req.url, true);
  if (url_object.pathname === "/api/parsetime") {
    var query = url_object.query;
    var date = new Date(query['iso']);

    return res.end(JSON.stringify({
      'hour': date.getHours(),
      'minute': date.getMinutes(),
      'second': date.getSeconds()
    }))
  }
  else if (url_object.pathname === "/api/unixtime") {
    var query = url_object.query;
    var date = new Date(query['iso']);

    return res.end(JSON.stringify({
      'unixtime': date.getTime()
    }))
  }
  else {
    res.writeHead(404);
    return res.end("Invalid API request");
  }

})
server.listen(process.argv[2]);
