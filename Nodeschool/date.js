var date = new Date();
var str = date.getFullYear() + "-";

function pad_with_zeros (num) {
  return (num < 10 ? '0' : '') + num;
}

str += pad_with_zeros(date.getMonth()+1) + "-";
str += pad_with_zeros(date.getDate()) + " ";
str += pad_with_zeros(date.getHours()) + ":";
str += pad_with_zeros(date.getMinutes()) + "\n";

console.log(str);
