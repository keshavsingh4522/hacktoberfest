// Contributer: Kritik Agarwal <https://github.com/Kritik007>

// Compile using cmd: g++ client1.cpp -o client1 -lwsock32 -lws2_32

// Using TCP/IP sockets, write a client server program to say hello to each other or echo the message.

#include <bits/stdc++.h>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
    string ipAddress = "127.0.0.1"; // IP Address of the server
    int port = 54000;               // listening port # on the server
    // Initializing winsock
    WSAData data;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);
    if (wsResult != 0)
    {
        cerr << "<!> Can't start winsock, Error #" << wsResult << endl;
        return 0;
    }
    // Creating socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        cerr << "<!> Can't create a socket, Error #" << WSAGetLastError() << endl;
        return 0;
    }
    // Filling in a hint structure
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
    // Connecting to server
    int connResult = connect(sock, (struct sockaddr *)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR)
    {
        cerr << "<!> Can't connect to server, Error #" << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return 0;
    }
    // Sending and Receiving data
    char buf[4096];
    string userInput;
    do
    {
        // Prompting client for some text
        cout << "> ";
        getline(cin, userInput);
        // Making sure client typed something
        if (userInput.size() > 0)
        {
            // Sending the text
            int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
            if (sendResult != SOCKET_ERROR)
            {
                // Waiting for response
                ZeroMemory(buf, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived > 0)
                {
                    // echoing response to console
                    cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
                }
            }
        }
    } while (userInput.size() > 0);
    // closing everything
    closesocket(sock);
    WSACleanup();
    return 0;
}