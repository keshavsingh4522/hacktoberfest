import java.util.*;
class anagrams{
    public static void checkanagram(String a, String b) {
        char arr1[]=new char[a.length()];
        char arr2[]=new char[b.length()];
        for(int i=0;i<a.length();i++){
            arr1[i]=a.charAt(i);
            arr2[i]=b.charAt(i);
        }

        Arrays.sort(arr1);
		Arrays.sort(arr2);
		boolean flag=false;
        for(int j=0;j<arr1.length;j++){
            if (arr1[j]==arr2[j]){
				flag=true;
            }
			else{
				flag=false;
				break;
			}
        }
		if(flag==true){
			System.out.println("Given strings are anagrams");
		}
		else{
            System.out.println("Given strings are not anagrams");
        }
	}
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
		System.out.print("Enter the first string:");
        String a = scan.next();
        System.out.print("Enter the second string:");
		String b = scan.next();
		if(a.length()==b.length()){
			checkanagram(a, b);
		}
		else{
			System.out.print("Not anagrams becouse length of both the string is different");
		}
    }
}
