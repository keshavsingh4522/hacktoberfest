public class PrimeExample{    
 	public static boolean prime(int a){
		if(a==2) {
			return true;
		}
		for(int i=2; i<=Math.sqrt(a); i++) {
			if(a%i==0) {
		    return false;
			}
				
		}
		return true;
	}
 public static void main(String args[]){          
  int n=3;//it is the number to be checked    
  System.out.println(prime(n));
}    
}   
