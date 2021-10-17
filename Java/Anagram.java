import java.util.*;
public class Anagram {
	    static boolean isAnagram(String a, String b) {
	        // Complete the function
	    	a=a.toLowerCase();
	    	b=b.toLowerCase();
	        char[] c=a.toCharArray();
	        char[] d=b.toCharArray();
	        boolean res;
	        Arrays.sort(c);
	        String A=Arrays.toString(c);
	        Arrays.sort(d);
	        String B=Arrays.toString(d);
	        if(A.equals(B)){
	            res=true;
	            }
	        else {
	            res=false;}
	        return res;
	    }

	    public static void main(String[] args) {
	    
	        Scanner scan = new Scanner(System.in);
	        String a = scan.next();
	        String b = scan.next();
	        scan.close();
	        boolean ret = isAnagram(a, b);
	        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
	    }
	}


