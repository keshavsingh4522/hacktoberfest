package Recursion;

public class StringSubsequent {

	public static String[] StringSubsequent(String input) {
		
		if(input.length()==0) {
			String[] ans = {" "};
			return ans;
		}
		
		
		String[] smallAns = StringSubsequent(input.substring(1)); 
		String[] ans =  new String[2 * smallAns.length];
		
		for(int i=0;i<smallAns.length;i++) {
			ans[i] = smallAns[i];
			}
		
		for(int i=0;i<smallAns.length;i++) {
			ans[i + smallAns.length] = input.charAt(0) + smallAns[i];
			}
		return ans;
		}
			
	
	public static void main(String[] args) {
		
		 String input = "xyz";
		 String[] ans = StringSubsequent(input);
		 for(int i=0;i<ans.length;i++) {
				System.out.println(ans[i]);
			}
		 
	}
}
