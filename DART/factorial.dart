// Program to find the factorial of a number.

// Factorial (denoted by !) of a number is the product of all the positive integers less than or equal to the number itself. 

// Eg - 5! = 120 (1 x 2 x 3 x 4 x 5 = 120)

// Program
// Define a Function to find the Factorial.
int factorial(int num) {
  
  // Initialise fac with 1.
  int fac = 1;
  
  // For loop to traverse numbers from 1 to the number itself.
  for (var i = 1; i <= num; i++){
    
    // Multiply the number.
    fac = fac * i;
  }
  
  // Return the Factorial.
  return fac;
}

void main() {
  
  // Test the Function
  print(factorial(5));  //120
}


