
function binToDec() {

  var str = document.getElementById("bin").value;
  var output = parseInt(str, 2);
  return document.getElementById("dec").value = output;
}

function binreset() {
  document.getElementById("dec").value = "";
  document.getElementById("bin").value = "";
}

