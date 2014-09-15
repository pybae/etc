var http = require('http');
var url = require('url');

function parsedate (date) {
  return {
    'hour': date.getHours(),
    'minute': date.getMinutes(),
    'second': date.getSeconds()
  }
}

function unixdate (date) {
  return { 'unixtime': date.getTime() }
}

var server = http.createServer(function (req, res) {

  var url_object = url.parse(req.url, true);
  var result;

  var query = url_object.query;
  var date = new Date(query['iso']);

  if (url_object.pathname === "/api/parsetime")
    result = parsedate(date);
  else if (url_object.pathname === "/api/unixtime")
    result = unixdate(date);

  if (result) {
    res.writeHead(200, { 'Content Type': 'application/json' });
    res.end(JSON.stringify(result));
  }
  else {
    res.writeHead(404);
    return res.end("Invalid API request");
  }

})
server.listen(process.argv[2]);
