import java.util.*;
class factorial_by_recursion {
    
    static int factorial(int k)
    {
        if (k == 0)
            return 1;
 
        return k * factorial(k - 1);
    }
 
    
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println("Factorial of " + num
                           + " is " + factorial(num));
    }
}