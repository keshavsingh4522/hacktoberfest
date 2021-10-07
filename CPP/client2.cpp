// Contributer: Kritik Agarwal <https://github.com/Kritik007>

// Compile using cmd: g++ client2.cpp -o client2 -lwsock32 -lws2_32

// Using TCP/IP sockets, write a client server program to make client sending the file name
// and the server to send back the contents of the requested file if present.

#include <bits/stdc++.h>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
    string ipAddress = "127.0.0.1"; // IP Address of the server
    int port = 7891;                // listening port # on the server
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
    else
        cout << "\n~> Client is connected to Server." << endl;
    // Sending and Receiving data
    char buf[4096], fname[50];
    string userInput;
    cout << "\nEnter File Name:~> ";
    getline(cin, userInput);
    cout << endl;
    int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
    if (sendResult != SOCKET_ERROR)
    {
        // Waiting for response from server
        ZeroMemory(buf, 4096);
        int bytesReceived = recv(sock, buf, sizeof(buf), 0);
        if (bytesReceived > 0)
            cout << "<- Requested File Data from Server ->\n\n"
                 << string(buf, 0, bytesReceived) << endl;
    }
    closesocket(sock); // Closing socket
    WSACleanup();      // Cleaningup Winsock
    return 0;
}