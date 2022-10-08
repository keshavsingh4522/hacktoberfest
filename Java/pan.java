import java.util.Scanner;

public class pan {
public static boolean isValidPan(String Pan) {
	
	
		return Pan !=null && Pan.matches("[A-Z]{5}[0-9]{4}[A-Z]{1}");
		
	}

public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	
	String pan = sc.nextLine();
	System.out.println(isValidPan(pan));
}

}
