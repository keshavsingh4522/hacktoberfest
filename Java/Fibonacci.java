package BJP;

public class Fibonacci {
    public static void main(String args[]){
        int n1=0,n2=1,n3,fib=10;
        System.out.print("Fibonacci series: "+ n1+ " "+ n2+" ");
        for(int i=2;i<fib;i++){
            n3=n2+n1;
            System.out.print(n3+" ");
            n1=n2;
            n2=n3;
        }
    }
}
