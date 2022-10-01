void fib(int n){
  var a = -1;
  var b = 1;
  var c = 0;
//   Initial Values to print from start (from 0 or 1 numbers)
  for (var i = 1; i <= n; i++){
    print('$c ');
    c = a+b;
    a = b;
    b = c;
//     Passing values to other variables by adding
  }
  }
//   fib(10);
