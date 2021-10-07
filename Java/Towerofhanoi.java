package Recursion;

public class Towerofhanoi {

    static void towerofHanoi(int n, char src, char des, char helper) {
        if (n == 0)
            return;
        towerofHanoi(n - 1, src, helper, des);
        System.out.println("Move " + n + " from " + src + " to " + des);
        towerofHanoi(n - 1, helper, des, src);
    }

    public static void main(String[] args) {
        towerofHanoi(3, 'A', 'C', 'B');
    }
}
