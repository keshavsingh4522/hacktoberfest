//Pattern
// 3 3 3 3 3 
// 3 2 2 2 3 
// 3 2 1 2 3 
// 3 2 2 2 3 
// 3 3 3 3 3 

public class MatrixPattern{
   public static void main(String arg[]){
      int N=3;
      int dbld_N=2*N;
      for(int i=1;i<=dbld_N-1;i++){
       for(int j=1;j<=dbld_N-1;j++){  
         int atEveryIndex=N+1- Math.min(Math.min(i,j),Math.min(dbld_N-i,dbld_N-j));
         System.out.print(atEveryIndex+" ");
       }
       System.out.println();
     }
   }
  
