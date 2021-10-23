import java.io.*;
import java.util.*;
 
class PascalTriangle {
    public int factorial(int i)
    {
        if (i == 0)
            return 1;
        return i * factorial(i - 1);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of rows:");
        int n = sc.nextInt(), i, j;
        PascalTriangle g = new PascalTriangle();
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n - i; j++) {
 
                // for left spacing
                System.out.print(" ");
            }
            for (j = 0; j <= i; j++) {
 
                // nCr formula
                System.out.print(
                    " "
                    + g.factorial(i)
                          / (g.factorial(i - j)
                             * g.factorial(j)));
            }
 
            // for newline
            System.out.println();
        }
    }
}