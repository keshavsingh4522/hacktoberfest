import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println("Enter the number : ");
        Scanner scan = new Scanner(System.in);
        int limit = scan.nextInt();
        int first_num = 0;
        int second_num = 1;
        int next_num = 0;
        int i = 0;
        for (i=1;i<=limit;i++){
            System.out.println(first_num+", ");
            next_num = first_num + second_num;
            first_num = second_num;
            second_num = next_num;
        }
        scan.close();
    }
}
