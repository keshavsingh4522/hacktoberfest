public class Counter {
    private int count;

    // Constructor to initialize the counter
    public Counter() {
        this.count = 0;
    }

    // Method to increment the counter
    public void increment() {
        count++;
    }

    // Method to decrement the counter
    public void decrement() {
        count--;
    }

    // Method to get the current count value
    public int getCount() {
        return count;
    }

    public static void main(String[] args) {
        Counter myCounter = new Counter(); // Create a new counter object
        System.out.println("Initial Count: " + myCounter.getCount()); // Output: Initial Count: 0

        myCounter.increment(); // Increment the counter
        System.out.println("Count after increment: " + myCounter.getCount()); // Output: Count after increment: 1

        myCounter.decrement(); // Decrement the counter
        System.out.println("Count after decrement: " + myCounter.getCount()); // Output: Count after decrement: 0
    }
}
