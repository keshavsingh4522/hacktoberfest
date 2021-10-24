 class l3 { 
  public static void main(String[] a1) { 

        Double result; 
    double number1 = Double.parseDouble(a1[0]);     char operator = a1[1].charAt(0); 
    double number2 = Double.parseDouble(a1[2]); 
 
    switch (operator) { 
               case '+': 
                result = number1 + number2; 
                System.out.println(number1 + " + " + number2 + " = " + result);                 break; 
               case '-': 
                result = number1 - number2; 
                System.out.println(number1 + " - " + number2 + " = " + result);                 break; 
               case 'x': 
                result = number1 * number2; 
                System.out.println(number1 + " * " + number2 + " = " + result);                 break; 
               case '/': 
                result = number1 / number2; 
                System.out.println(number1 + " / " + number2 + " = " + result);                 break;         case '%': 
                result = number1 % number2; 
                System.out.println(number1 + " % " + number2 + " = " + result);                 break;               default: 
                System.out.println("Invalid operator!");                 break; 
        } 
  } 
} 
 
