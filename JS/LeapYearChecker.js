
function isLeapYear(year) {
  // check for leap year
  // Algorithm based on logic from here - https://en.wikipedia.org/wiki/Leap_year#Algorithm
  var a = year % 4;
  var b = year % 100;
  var c = year % 400;
  var result = (a == 0 || c == 0) ? true : (b == 0);
  console.log ("Is Year " + year + " a leap year? " + result);
  return result;
}

console.log (isLeapYear(2000));
console.log (isLeapYear(2001));
console.log (isLeapYear(2004));
console.log (isLeapYear(2020));
console.log (isLeapYear(2021));

// check bounds for year param input - should result in false.
console.log (isLeapYear("yoohoo"));

