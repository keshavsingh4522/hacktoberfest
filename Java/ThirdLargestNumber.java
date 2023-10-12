public class ThirdLargestNumber {
    public static void main(String[] args) {
        // Create an array of 10 numbers
        int[] numbers = {10, 5, 8, 25, 18, 13, 30, 15, 7, 21};

        // Initialize variables to store the three largest numbers
        int firstLargest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        int thirdLargest = Integer.MIN_VALUE;

        // Iterate through the array to find the three largest numbers
        for (int num : numbers) {
            if (num > firstLargest) {
                thirdLargest = secondLargest;
                secondLargest = firstLargest;
                firstLargest = num;
            } else if (num > secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = num;
            } else if (num > thirdLargest) {
                thirdLargest = num;
            }
        }

        // The thirdLargest variable now contains the 3rd largest number
        System.out.println("The 3rd largest number is: " + thirdLargest);
    }
}
