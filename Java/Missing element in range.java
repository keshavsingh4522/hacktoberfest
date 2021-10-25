//considering size n-1 not n as per the question;
import java.util.Scanner;
class Main
{
  public static int MissingElement(int a[],int n){
  int flag=0,i,pos=0;
  for(i=1;i<=n;i++){
    for(int j=0;j<n-1;j++){
      if(i==a[j]){
        flag=1;
        break;
      }
    }
    if(flag==0){
      pos=i;
      break;
    }
    flag=0;
  }
  return pos;
}
  public static void main(String[] args)
    {
         Scanner sc=new Scanner(System.in);
int i,n;
n=sc.nextInt();
     int a[]=new int[n];

         for(i=0;i<n-1;i++)
     {
         a[i]=sc.nextInt();
     }
         int missingNumber=MissingElement(a,n);  // receive array and no. of elements as argument .
 System.out.println(missingNumber);
    }
}
