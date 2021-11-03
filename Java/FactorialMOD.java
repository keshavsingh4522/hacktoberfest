import java.math.BigInteger;
import java.util.Scanner;

public class FactorialMOD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter value: ");
        BigInteger value = input.nextBigInteger();
        System.out.print("Enter modWith: ");
        BigInteger modWith = input.nextBigInteger();
        try {
            System.out.println("Factorial of " + value + " is " + findFactorial(value).mod(modWith));
        } catch (StackOverflowError e) {
            System.err.println("Stack Overflow Error!!");
        }
    }

    public static BigInteger findFactorial(BigInteger n) {
        return n.equals(BigInteger.ZERO) ? BigInteger.ONE : n.multiply(findFactorial(n.subtract(BigInteger.ONE)));
    }
}
