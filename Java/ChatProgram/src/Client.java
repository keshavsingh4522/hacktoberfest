import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    Socket socket;
    BufferedReader br;
    PrintWriter out;
    public Client(){
        try{
            socket = new Socket("127.0.0.1",7777);
            System.out.println("Connection Establsihed");
            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(socket.getOutputStream());

            startReading();
            startWriting();
        }
        catch(Exception e){
            e.printStackTrace();
            System.exit(1);
        }
    }
    public void startReading(){
        Runnable r1 =() ->{
            while(true){
                try {
                    String mssg = br.readLine();
                    if (mssg.equals("-101")) {
                        System.out.println("Server Terminated The Chat");
                        socket.close();
                        br.close();
                        System.exit(0);
                    }
                    System.out.println("Server : " + mssg);
                }
                catch(Exception e){
                    e.printStackTrace();
                    System.exit(1);
                }
            }
        };
        new Thread(r1).start();
    }
    public void startWriting(){
        Runnable r2 = () ->{
            while(true) {
                try {
                    BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
                    String content = br2.readLine();
                    out.println(content);
                    out.flush();
                    if(content.equals("-101")){
                        System.out.println("Connection Terminated");
                        socket.close();
                        System.exit(0);
                    }
                }
                catch(Exception e){
                    e.printStackTrace();
                    System.exit(1);
                }
            }
        };
        new Thread(r2).start();
    }
    public static void main(String[] args){
        System.out.println("Trying To Establish Connection To Server");
        new Client();
    }
}
