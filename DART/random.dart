import 'dart:math';

void main() {
  var random = new Random();

  print(random.nextBool()); //true or false

  print(random.nextInt(75)); // number between 0 - 75

  print(random.nextDouble()); // double value 0.0 to 1.0
}
