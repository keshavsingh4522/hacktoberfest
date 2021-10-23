import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MaxCharacterOccurance {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		System.out.print("Enter Text: ");
		String input = scan.nextLine();

		char[] charArray = input.toCharArray();
		HashMap<Character, Integer> countMap = new HashMap<Character, Integer>();
		for (char currentChar : charArray) {
			if (countMap.containsKey(currentChar)) {
				countMap.put(currentChar, countMap.get(currentChar) + 1);
			} else {
				countMap.put(currentChar, 1);
			}
		}

		// Determining maximum occurrence
		int max = 0;
		for (Integer i : countMap.values()) {
			if (max < i) {
				max = i;
			}
		}

		// Printing all characters with maximum occurance
		for (Map.Entry<Character, Integer> e : countMap.entrySet()) {
			if (e.getValue() == max) {
				System.out.println("The letter '" + e.getKey() + "' is used " + max + " time(s).");
			}
		}

		scan.close();
	}

}
