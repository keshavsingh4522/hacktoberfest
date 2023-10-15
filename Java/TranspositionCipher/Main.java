import static java.lang.System.*;//as it's static we don't need to write System repeatedly
import java.util.*;
import java.io.*;
// import ciphers.transposition_cipher.TranspositionCipher; : not working

/**
 * Mini-Project for implementing different crypto algorithms
 */

class TranspositionCipher {

    public boolean checkKey(String key) {

        try {
            // check key length
            if (!(key.length() < 10)) {
                throw new Exception("Key is too long. Only allow cipher keys with length up to 10.");
            }
            // will throw an exception for non-numeric value
            int keyInInt = Integer.parseInt(key);

            /*if (checkForRepeatedDigitInKey(key) && checkForMissingKeyValue(key)) {
                return true;
            }*/

            if(checkKeyDigits(key) && key.contains("0"))
            {
                return true;
            }

        } catch (NumberFormatException nfe) {
            err.println("Please enter Integer value");
        }

        catch (Exception e) {
            err.println("Exception: " + e.getMessage());
        }

        return false;
    }

    /*public static boolean checkForMissingKeyValue(String key) {
        int keyLength = key.length();

        for (int i = 0; i < keyLength; i++) {
            if (!key.contains(Integer.toString(i))) {
                System.out.println("Each digit of key must be within the range from 0 to the length of the key.");
                return false;
            }
        }
        return true;
    }

    public static boolean checkForRepeatedDigitInKey(String key) {
        // needs to check whether each number in the key is unique.
        String curDigit = "";
        for (int i = 0; i < key.length(); i++) {
            if (i < key.length() - 1) {
                curDigit = key.substring(i, i + 1);
                String restOfKey = key.substring(i + 1);
                if (restOfKey.contains(curDigit)) {
                    System.out.println("Cannot have recurring numbers.");
                    return false;
                }
            }
        }
        return true;
    }*/

    public static boolean checkKeyDigits(String key)
    {
    	int N = key.length();
    	int sum = 0;
    	int digit = 0;
    	for (int i = 0; i < N; i++)
    	{
    		digit = Integer.parseInt(Character.toString(key.charAt(i)));
    		sum += digit;
    	}
    	int expectedSum = ((N)*(N-1)/2);
    	System.out.println(Integer.toString(sum));
    	System.out.println(Integer.toString(expectedSum));
    	if(sum == expectedSum)
    		return true;
    	else
    		return false;
    }

    // function for reading a file
    public String readFromInputFile(String inputFilename) {
        String lines = "";
        String content = "";

        try {
            BufferedReader fileReader = new BufferedReader(new FileReader(inputFilename));

            lines = fileReader.readLine();

            while (lines != null) {
                content = content + lines;

                if ((lines = fileReader.readLine()) != null) {
                    content = content + " ";
                }
            }

            fileReader.close();
            return content;

        } catch (IOException ioe) {
            System.out.println("Error reading file.");
        }
        return lines;
    }

    public boolean writeToOutputFile(String data, String outputFilename) {

        try {
            PrintWriter pw = new PrintWriter(outputFilename);
            pw.print(data);
            pw.close();
            return true;
        } catch (IOException ioe) {
            System.out.println("Failed to write to output file.");
        }

        return false;

    }

    public String encryptUsingTransposition(String input, String key) {

        int numberOfCols = key.length();
        int numberOfRows = 0;

        if (input.length() % numberOfCols > 0) {
            numberOfRows = (input.length() / numberOfCols) + 1;
        }

        if (input.length() % numberOfCols == 0) {
            numberOfRows = input.length() / numberOfCols;
        }

        char[][] characterMap;
        characterMap = new char[numberOfRows][numberOfCols];

        for (int row = 0; row < numberOfRows; row++) {
            for (int col = 0; col < numberOfCols; col++) {
                characterMap[row][col] = ' ';
            }
        }
        int rows = 0;
        int cols = 0;

        for (int i = 0; i < input.length(); i++) {
            characterMap[rows][cols] = input.charAt(i);
            cols++;
            if (cols == numberOfCols) {
                rows++;
                cols = 0;
            }
        }

        // need to append back into a string according to the key.
        int curCols = 0;
        String result = "";

        for (int i = 0; i < key.length(); i++) {

            if (i == key.length() - 1) {
                curCols = Integer.parseInt(key.substring(i));
            } else {
                curCols = Integer.parseInt(key.substring(i, i + 1));
            }

            for (int k = 0; k < numberOfRows; k++) {
                result = result + characterMap[k][curCols];
            }

        }

        return result;
    }

    public String decryptUsingTransposition(String data, String key) {
        int numberOfCols = key.length();
        int numberOfRows = 0;

        if (data.length() % numberOfCols > 0) {
            numberOfRows = (data.length() / numberOfCols) + 1;
        }

        if (data.length() % numberOfCols == 0) {
            numberOfRows = data.length() / numberOfCols;
        }

        char[][] characterMap = new char[numberOfRows][numberOfCols];

        for (int row = 0; row < numberOfRows; row++) {
            for (int col = 0; col < numberOfCols; col++) {
                characterMap[row][col] = ' ';
            }
        }

        int curCols = 0;
        int dataIndex = 0;
        String result = "";

        // Fills up the columns of the characterMap by column.
        for (int i = 0; i < key.length(); i++) {
            if (i == key.length() - 1) {
                curCols = Integer.parseInt(key.substring(i));
            } else {
                curCols = Integer.parseInt(key.substring(i, i + 1));
            }

            for (int k = 0; k < numberOfRows; k++) {
                if (dataIndex < data.length()) {
                    characterMap[k][curCols] = data.charAt(dataIndex);
                    dataIndex++;
                }
            }
        }

        // Reads characterMap left to right, from row 0 to last row.
        for (int row = 0; row < numberOfRows; row++) {
            for (int col = 0; col < numberOfCols; col++) {
                result = result + characterMap[row][col];
            }
        }

        return result;

    }

}

public class Main {

    // just so that we don't have to write sop repeatedly

    public static void print(String str) {
        System.out.print(str);
    }

    public static void println(String str) {
        System.out.println(str);
    }

    public void printerr(Exception e) {
        err.println("Error occured: " + e);
    }

    public static void decorate(char c) {
        for (int i = 0; i < 36; i++) {
            print(Character.toString(c));
        }

    }

    // source: stackOverflow
    public static void clearScreen() {
        try {
            // for windows
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            // for linux based O.S
            else
                Runtime.getRuntime().exec("clear");
        } catch (Exception ex) {
        }
    }

    public static void getMenu() throws InterruptedException, InputMismatchException, IOException {
        Scanner scan = new Scanner(System.in);
        String plainText;
        String encryptedText;
        String decryptedText;
        String key;
        String inputFile;
        String outputFile;
        TranspositionCipher tCipher = new TranspositionCipher();
        do {

            clearScreen();
            decorate('-');
            println("\nChoose one of the following options:");
            decorate('-');
            println("\n0. Exit");
            println("1. Encrypt Text using Transposition Cipher");
            println("2. Decrypt Text using Transposition Cipher");
            println("3. Encrypt File using Transposition Cipher");
            println("4. Decrypt File using Transposition Cipher");
            println("11. Rules for selecting Transposition key");
            print("Enter your option : ");
            int option = scan.nextInt();

            switch (option) {

            case 0:
                println("Exiting......");
                System.exit(0);

            case 1:
                scan.nextLine(); // because as we press enter after selecting the option it might read it as out
                                 // plain text
                print("Enter Text to be Encrypted : ");
                plainText = scan.nextLine();

                print("Enter an integer key (checkout option 11 for rules of choosing a key) : ");
                key = scan.next();

                if (!tCipher.checkKey(key)) {
                    println("Incorrect Key check out option 11");
                    println("refreshing in 3 seconds...");
                    Thread.sleep(2000);
                    break;
                }
                println("key is correct");

                encryptedText = tCipher.encryptUsingTransposition(plainText, key);

                println("Encrypted text is : " + encryptedText);

                print("Screen will automatically refresh in 4 seconds....");
                Thread.sleep(4000);

                break;

            case 2:
                scan.nextLine(); // same as above
                print("Enter Text to be Decrypted : ");
                final String enText = scan.nextLine();
                print("Enter the key which you previously entered : ");
                key = scan.next();

                if (!tCipher.checkKey(key)) {
                    println("Incorrect Key check out option 11");
                    println("refreshing in 3 seconds...");
                    Thread.sleep(3000);
                    break;
                }

                println("key is correct");

                decryptedText = tCipher.decryptUsingTransposition(enText, key);

                println("Decrypted text is : " + decryptedText);

                print("Screen will automatically refresh in 4 seconds....");

                Thread.sleep(6000);

                break;

            case 3:
                println("Enter Input File Name : ");
                inputFile = scan.next();

                println("Enter Output File Name : ");
                outputFile = scan.next();

                println("Enter Key : ");
                key = scan.next();

                if (!tCipher.checkKey(key)) {
                    println("Incorrect Key check out option 11");
                    println("refreshing in 3 seconds...");
                    Thread.sleep(2000);
                    break;
                }
                println("key is correct");

                plainText = tCipher.readFromInputFile(inputFile);
                encryptedText = tCipher.encryptUsingTransposition(plainText, key);

                if (tCipher.writeToOutputFile(encryptedText, outputFile)) {
                    println("successfully copied Encrypted message to " + outputFile);
                } else {
                    throw new IOException("IO exception file output error ");
                }

                break;

            case 4:
                println("Enter Input File Name : ");
                inputFile = scan.next();

                println("Enter Output File Name : ");
                outputFile = scan.next();

                println("Enter Key : ");
                key = scan.next();

                if (!tCipher.checkKey(key)) {
                    println("Incorrect Key check out option 11");
                    println("refreshing in 3 seconds...");
                    Thread.sleep(2000);
                    break;
                }
                println("key is correct");

                plainText = tCipher.readFromInputFile(inputFile);
                decryptedText = tCipher.decryptUsingTransposition(plainText, key);

                if (tCipher.writeToOutputFile(decryptedText, outputFile)) {
                    println("successfully copied Decrypted message to " + outputFile);
                } else {
                    throw new IOException("IO exception file output error ");
                }

                break;

            case 11:
                println("Rules for selecting a key : ");
                println("1. Key shouldn't be too long, allowing cipher keys with length up to 10.");
                println("2. It shouldn't have recurring numbers.");
                println("3. Each digit of key must be within the range from 0 to the length of the key.");
                println("refreshing in 5 seconds...");
                Thread.sleep(5000);

                break;
            default:
                println("Enter a valid option :) ");
                Thread.sleep(1000);
                break;
            }

        } while (true);

    }

    public static void main(String... args) {
        try {
            getMenu();
        } catch (IOException ioe) {
            err.println(ioe);
        } catch (InputMismatchException ime) {
            println("Enter one of the valid option");
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}