package com.augustoaccorsi;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Integer> line1 = new ArrayList<>();
        List<Integer> line2 = new ArrayList<>();
        List<Integer> line3 = new ArrayList<>();
        List<Integer> line4 = new ArrayList<>();
        List<Integer> line5 = new ArrayList<>();
        List<Integer> line6 = new ArrayList<>();
        List<List<Integer>> arr = new ArrayList<>();

        line1.add(1); line1.add(1); line1.add(1); line1.add(0); line1.add(0); line1.add(0);
        line2.add(0); line2.add(1); line2.add(0); line2.add(0); line2.add(0); line2.add(0);
        line3.add(1); line3.add(1); line3.add(1); line3.add(0); line3.add(0); line3.add(0);
        line4.add(0); line4.add(0); line4.add(2); line4.add(4); line4.add(4); line4.add(0);
        line5.add(0); line5.add(0); line5.add(0); line5.add(2); line5.add(0); line5.add(0);
        line6.add(0); line6.add(0); line6.add(1); line6.add(2); line6.add(4); line6.add(0);

        arr.add(line1); arr.add(line2); arr.add(line3);
        arr.add(line4); arr.add(line5); arr.add(line6);

        System.out.println(hourglassSum(arr));

    }

    public static void printArr(List<List<Integer>> arr) {
        for (List<Integer> list : arr) {
            System.out.print("  [");
            for (Integer item : list) {
                System.out.print("  " + item + ", ");
            }
            System.out.println("], ");
        }
    }

    public static int hourglassSum(List<List<Integer>> arr) {
        //printArr(arr);
        int sum = 0, max = -999999999, index = 0, aux = 0, index1 = 0;
        for (List<Integer> list : arr) {
            try {
                do{
                sum += (list.get(0 + index) + list.get(1 + index) + list.get(2 + index));
                sum += (arr.get(1 + index1).get(1 + index));
                sum += (arr.get(2 + index1).get(0 + index) + arr.get(2 + index1).get(1 + index) + arr.get(2 + index1).get(2 + index));
                if (sum > max) {
                    max = sum;
                }
                sum = 0;
                index++;
                aux++;
                }while(aux < 5);
                index++;
                index1++;
                aux = 0;
            } catch (Exception e){
                sum = 0;
                index = 0;
                index1++;
                aux = 0;
            }
        }
        return max;
    }
}