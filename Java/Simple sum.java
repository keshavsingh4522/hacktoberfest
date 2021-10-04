//Complete the simpleArraySum function in the editor below. It must return the sum of the array elements as an integer.



//complexity = 7

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class A {

 
     public static void main(String[] args) {
     
     Scanner s = new Scanner(System.in);
         int A = s.nextInt();
          int[] ar = new int[A];
         int B;
         for( int t=0;t<A;t++)
         {
               B = s.nextInt();
               ar[t]=B;
         }
          int sum=0;
         for( int i=0;i<A;i++)
         {
         sum = sum+ar[i];
         }
         System.out.println(""+sum);
     }
}

    
