var net = require('net');

function pad_with_zeros (num) {
  return (num < 10 ? '0' : '') + num;
}

var server = net.createServer(function (socket) {
  var date = new Date();
  var str = date.getFullYear() + "-";

  str += pad_with_zeros(date.getMonth()+1) + "-";
  str += pad_with_zeros(date.getDate()) + " ";
  str += pad_with_zeros(date.getHours()) + ":";
  str += pad_with_zeros(date.getMinutes()) + "\n";

  socket.end(str);
})

server.listen(process.argv[2]);
