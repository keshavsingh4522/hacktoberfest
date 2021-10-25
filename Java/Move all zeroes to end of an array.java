import java.util.*;
class Main
{
  public static void moveZerosToEnd(int a[]){
  int k=0;
  for(int i=0;i<a.length;i++){ // move all non zero elements to one side first then move zero to last
    if(a[i]!=0){
      a[k++]=a[i];
    }
  }
  while(k<a.length){ 
    a[k++]=0;
  }
}
  public static void main(String[] args)
 {
 Scanner sc = new Scanner(System.in);
 int n = sc.nextInt();
 int[] a = new int[n];
 for (int i = 0; i < n; i++)
 {
 a[i] = sc.nextInt();
 }
 moveZerosToEnd(a);
 for (int i = 0; i < a.length; i++)
 {
 System.out.print(a[i]+" ");
 }
 }
}

