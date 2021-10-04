import java.util.*;

public class TrappingRainWater {

    public int maxWater(int[] array) {
        int n = array.length;
        int res = 0;
        int[] Lmax = new int[n];
        int[] Rmax = new int[n];
        Lmax[0] = array[0];
        for (int i = 1; i < n; i++) {
            Lmax[i] = Math.max(Lmax[i - 1], array[i]);
        }
        Rmax[n - 1] = array[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            Rmax[i] = Math.max(Rmax[i + 1], array[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            res += Math.min(Lmax[i], Rmax[i]) - array[i];
        }
        return res;

    }

    public static void main(String[] args) {

        TrappingRainWater trp = new TrappingRainWater();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array: ");

        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter number " + i + 1);
            array[i] = scanner.nextInt();
        }
        System.out.print("The maximum water that can be hold is " + trp.maxWater(array));
    }
}
