//console.log(process.argv);
//console.log(process.argv[2]);

var sum = 0;
for (var i = 2, l = process.argv.length; i < l; i++) {
  var v = process.argv[i];
  sum += Number(v);
}

console.log(sum);
