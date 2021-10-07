package Recursion;

public class moveXend {

    public static String moveXryt(String s) {
        if (s.length() <= 1)
            return s;
        if (s.charAt(0) == 'x')
            return moveXryt(s.substring(1)) + "x";
        else
            return s.charAt(0) + moveXryt(s.substring(1));
    }

    public static void main(String[] args) {
        System.out.println(moveXryt("axxbdxcefxhix"));
    }
}
