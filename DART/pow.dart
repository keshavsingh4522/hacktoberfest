// Program to find the pow of a number.

// Eg - 5^3 = 125 (5 x 5 x 5 = 125)

// Program
// Define a Function to find the pow.
int pow(int base, int _pow) {
  
  // Initialise result with 1.
  int result = 1;

  if(_pow < 0){
    // if pow less than 0 function will return -1
    return -1;
  } else if( _pow == 0){
    // pow 0 = 1
    return 1;
  } else{
    for (var i = 0; i < _pow; i++){
      // Multiply the result with base.
      result = result * base;
    }
  }
  
  // Return the pow of base.
  return result;
}

void main() {
  
  // Test the Function
  print(pow(5, 3));  //125
}




