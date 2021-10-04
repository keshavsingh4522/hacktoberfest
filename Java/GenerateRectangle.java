import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class GenerateRectangle {
    public static String generateRectangle(int x, int y) {
        String xString = "⬜".repeat(x) + "\n";
        return xString.repeat(y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter a x length: ");
            int x = scanner.nextInt();
            System.out.print("\nEnter a y height: ");
            int y = scanner.nextInt();
            if (x < 0 || y < 0) {
                throw new IllegalArgumentException("Arguments cannot be negative!");
            } else if (x > 30000 || y > 30000) {
                throw new IllegalArgumentException("Arguments cannot be over 30,000!");
            } else {
                System.out.println(generateRectangle(x, y));
            }
        } catch (InputMismatchException exception) {
            System.out.println("You need to enter a number and it needs to be under or equal to 30,000.");
        } catch (NoSuchElementException exception) {
            System.out.println("You need to type an integer.");
        } catch (IllegalArgumentException exception) {
            System.out.print(exception.getLocalizedMessage());
        } catch (Exception exception) {
            System.out.println("You need to type a valid integer!");
        }
    }
}
