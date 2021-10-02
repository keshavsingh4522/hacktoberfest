import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Scanner;


public class DES {
  public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    System.out.print("Enter plaintext to be encrypted: ");
    plainText=in.nextLine();
    try {
      // Generate the key for DES in java
      KeyGenerator myGenerator=KeyGenerator.getInstance("DES");
      SecretKey desKey=myGenerator.generateKey();

      // Declare an object of class Cipher for DES
      Cipher desCipher=Cipher.getInstance("DES");

      // Set the DES cipher object into encryption mode
      desCipher.init(Cipher.ENCRYPT_MODE,desKey);

      // Translate the plaintext to be encrypted into an array of bytes
      // byte[] myBytes=
    }
    catch(Exception e) {

    }
  }
}
