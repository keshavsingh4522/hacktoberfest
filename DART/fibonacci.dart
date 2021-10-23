import 'dart:io';

void main() {
  int? order = int.parse(stdin.readLineSync()!);
  print(fibonacci(order));
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
