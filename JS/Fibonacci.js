function fib(n) {
  let phi = (1 + Math.sqrt(5)) / 2;
  return Math.round(Math.pow(phi, n) / Math.sqrt(5));
}
 
let n = 9;
  document.write(fib(n));