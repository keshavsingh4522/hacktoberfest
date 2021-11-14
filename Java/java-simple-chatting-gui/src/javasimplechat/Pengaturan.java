/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javasimplechat;

/**
 *
 * @author thinkpad
 */
public class Pengaturan {

    private static int portServer = 0;
    private int portClient = 0;
    private String ip = "";

    public static int getPortServer() {
        return portServer;
    }

    public static void setPortServer(int portServer) {
        Pengaturan.portServer = portServer;
    }

    public int getPortClient() {
        return portClient;
    }

    public void setPortClient(int portClient) {
        this.portClient = portClient;
    }

    public String getIp() {
        return ip;
    }

    public void setIp(String ip) {
        this.ip = ip;
    }

}
