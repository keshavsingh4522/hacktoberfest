import java.util.*;
public class fibonacci{
    public static int fib(int n){
        if(n==1){
            return array[0];
        }
        // base cases
        if(n==2){
            return array[1];
        }
        else{
            array[n-1] = fib(n-1) + fib(n-2);
            return (array [n-1]);
        }
    }
    public static void main(String args[]){
        int n;
        Scanner snr= new Scanner(System.in);
        n=snr.nextInt();
        snr.close();
        array[0]=0;
        array[1]=1;
        System.out.println(fib(n));
        // printing number in fibonacci series
    }
    static int array[]=new int[1000];
    // Declaring global array large enough
 }
