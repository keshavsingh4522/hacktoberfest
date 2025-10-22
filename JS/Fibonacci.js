//Code for Fibonacci series in JavaScript
const nthFibonacci = (n) => {
  // set the base case(fib[0] = 0, fib[1] = 1)
  let fib = [0, 1]
  for (let i = 2; i <= n; i++) {
      fib.push(fib[i - 1] + fib[i - 2]);
  }

  return fib[n];
}
