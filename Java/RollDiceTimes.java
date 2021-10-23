import java.util.*;

public class RollDiceTimes {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        Random rand = new Random();
        String again = ("y");
        int i;
    
        while (again.equalsIgnoreCase("y")) {
            for (i = 0; i < 6; i++) {
                int x = i + 1;
                System.out.println("Rolling the dice..." + x);
                int die1 = rand.nextInt(6) + 1;
                int die2 = rand.nextInt(6) + 1;
                System.out.println("Their values are:");
                System.out.println(die1 + " " + die2);
            }
            System.out.println("Roll them again (y = yes)?");
            again = keyboard.nextLine();
        }   
    }
}