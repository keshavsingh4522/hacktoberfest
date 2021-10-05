import java.util.*;

public class Median {
    public static void main (String[] args) 
    {
        Scanner in= new Scanner(System.in);
        int n =in.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) {
            arr[i]=in.nextInt();
        }
        Arrays.sort(arr);
        double median;
        if(n%2==0) {
            int m1=arr[n/2];
            int m2=arr[(n/2)-1];
            median = ((double)(m1+m2))/2;
            System.out.println(median);		
        }
        else {
            median=arr[n/2];
            System.out.println(median);	
        }
    }

}
