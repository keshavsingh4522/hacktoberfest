import java.time.Period;// Here We used Library take from java.time folder
import java.time.LocalDate;// same as above
import java.util.Scanner;// Here we insert a Scanner class for take user input

public class AgeCalculator {// here we created a Main Class inside the main class
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Here We Make Object for Scanner class ( For Take user input)

        System.out.print("Enter your birth year: ");
        int year = scanner.nextInt();// Here we call the scanner object  for int
        System.out.print("Enter your birth month: ");
        int month = scanner.nextInt();// Same here
        System.out.print("Enter your birth day: ");
        int day = scanner.nextInt();// also same

        AgeCalculator(year, month, day); // Here we passes parameter
        Calculator(year, month, day);// same here for calculate age

        scanner.close();// here we close the scanner.
    }

    public static void AgeCalculator(int year, int month, int day) {
        LocalDate dob = LocalDate.of(year, month, day);
        LocalDate curdob = LocalDate.now();
        Period date = Period.between(dob, curdob);

        System.out.printf("Age: %d years, %d months, and %d days%n", date.getYears(), date.getMonths(), date.getDays());
    }

    public static void Calculator(int year, int month, int day) {
        LocalDate dob = LocalDate.of(year, month, day);
        LocalDate curdob = LocalDate.now();
        Period date = Period.between(dob, curdob);

        if (curdob.getMonthValue() == dob.getMonthValue() && curdob.getDayOfMonth() == dob.getDayOfMonth()) { // here we check the condition
            System.out.println("Happy Birthday!");
        } else {
            System.out.printf("Age: %d years, %d months, and %d days%n", date.getYears(), date.getMonths(), date.getDays());

            // Calculate remaining days to the next birthday
            LocalDate nextBirthday = dob.withYear(curdob.getYear());
            if (nextBirthday.isBefore(curdob) || nextBirthday.isEqual(curdob)) {
                nextBirthday = nextBirthday.plusYears(1);
            }
            Period remainingDays = Period.between(curdob, nextBirthday); // here we check the remaining day
            System.out.printf("Remaining Days to Next Birthday: %d Days%n", remainingDays.getDays());
        }
    }
}
