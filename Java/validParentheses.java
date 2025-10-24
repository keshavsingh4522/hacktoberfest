import java.util.Scanner;
import java.util.Stack;

public class validParentheses {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        // Get input
        System.out.println("Enter a string of brackets:");
        String str = sc.nextLine();
        
        boolean isValid = checkValidParentheses(str);
        
        if (isValid) {
            System.out.println("The parentheses are valid!");
        } else {
            System.out.println("The parentheses are NOT valid!");
        }
    }
    
    
    public static boolean checkValidParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.isEmpty()) return false;
                
                char top = stack.pop();
                
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return stack.isEmpty();
    }
}

