class Palindrome{  //creating class
 public static void main(String args[]){  
  int r,sum=0,temp;//temporary variable    
  int n=454;// No to check for palindrom
  
  temp=n;   
  while(n>0){    
   r=n%10;  //getting remainder  
   sum=(sum*10)+r;    
   n=n/10;    
  }    
  if(temp==sum)    //checking
   System.out.println("palindrome number ");    
  else    
   System.out.println("not palindrome");    
  }  
}  
