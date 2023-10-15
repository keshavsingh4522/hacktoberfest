import java.io.*;
import java.util.*;
import java.net.*;
public class hostfinder {
    public static void main(String[] args)
    {
          // scanning Host
        Scanner sc = new Scanner(System.in);
      System.out.print("Enter website to find host : ");
      String host = sc.nextLine().trim();
        
        // try catch for exception handling 
        
        try {
            InetAddress iaddress = InetAddress.getByName(host);
  
            System.out.println("Host :" +iaddress.getHostName() +" Address : "+iaddress.getHostAddress());
        }
        catch (UnknownHostException e) {
            System.out.println("Exception Occured : "+e);
        }
    }
}
