// Java program to demonstrate working of extended
// Euclidean Algorithm


import java.util.*;
import java.lang.*;

public class EuclideanAlgorithms {
    public static void main(String[] args) {
        int a = 10;
        int b = 15; 
        int g;
        g = gcd(a, b);
        System.out.println("GCD(" + a +  " , " + b+ ") = " + g);
         
        a = 35; 
        b = 10;
        g = gcd(a, b);
        System.out.println("GCD(" + a +  " , " + b+ ") = " + g);
         
        a = 31; 
        b = 2;
        g = gcd(a, b);
        System.out.println("GCD(" + a +  " , " + b+ ") = " + g);
 
    }

    // extended Euclidean Algorithm
    public static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
         
        return gcd(b%a, a);
    }
}