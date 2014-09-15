var mymodule = require("./mymodule")

mymodule(process.argv[2], process.argv[3], function (err, list) {
  if (err) 
    return console.log("Error: " + err);

  list.forEach(function (entry) {
    console.log(entry);
  })
})
