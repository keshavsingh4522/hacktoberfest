import 'dart:io';

void main() {
  print("Enter a number: ");
    int num = int.parse(stdin.readLineSync());
  for (int i = 1; i <= 10; i++) {
    print("$num * $i = ${num * i}");
  }
}
