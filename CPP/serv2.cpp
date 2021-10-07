// Contributer: Kritik Agarwal <https://github.com/Kritik007>

// Compile using cmd: g++ serv2.cpp -o serv2 -lwsock32 -lws2_32

// Using TCP/IP sockets, write a client server program to make client sending the file name
// and the server to send back the contents of the requested file if present.

#include <bits/stdc++.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <fcntl.h>

using namespace std;

int main()
{
    // Initializing Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0)
    {
        cerr << "<!> Can't initialize winsock!! quitting..." << endl;
        return 0;
    }
    // Creating Socket
    SOCKET welcome = socket(AF_INET, SOCK_STREAM, 0);
    if (welcome == INVALID_SOCKET)
    {
        cerr << "<!> Can't create a socket!! quitting..." << endl;
        return 0;
    }
    // Binding the socket to an ipaddress and port
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(7891);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(welcome, (struct sockaddr *)&hint, sizeof(hint));
    cout << "~> Server is Online." << endl;
    listen(welcome, SOMAXCONN); // Telling Winsock that Socket is Listening
    // Waiting for client connection
    sockaddr_in client;
    int clientSize = sizeof(client);
    SOCKET clientSocket = accept(welcome, (struct sockaddr *)&client, &clientSize);
    if (clientSocket == INVALID_SOCKET)
    {
        cerr << "<!> Can't connect to client!! quitting..." << endl;
        return 0;
    }
    char host[NI_MAXHOST];    // Client's remote name
    char service[NI_MAXSERV]; // Service (a.k.a. port) the client is connected on
    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);
    if (getnameinfo((sockaddr *)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
        cout << "~> " << host << " connected on port " << service << endl;
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << "~> " << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
    closesocket(welcome); // Close listening socket
    // Accepting and echoing msg back to client
    int fd, n;
    char buf[4096], fname[50];
    while (true)
    {
        ZeroMemory(buf, 4096);
        // Waiting for client to send data
        int bytesReceived = recv(clientSocket, fname, 50, 0);
        if (bytesReceived == 0)
        {
            cout << "\n<!> Client Disconnected <!>" << endl;
            break;
        }
        if (bytesReceived == SOCKET_ERROR)
        {
            cerr << "<!> Error in recv(). quitting..." << endl;
            break;
        }
        // File handling
        cout << "Requesting for file ~> " << string(fname, 0, bytesReceived) << endl;
        fd = open(fname, O_RDONLY);
        if (fd < 0)
            send(clientSocket, "\n<!> File not found.\n", 15, 0);
        else
        {
            while ((n = read(fd, buf, sizeof(buf))) > 0)
                send(clientSocket, buf, n, 0);
            cout << "~> Requested file data sent" << endl;
        }
    }
    closesocket(clientSocket); // Closing the socket
    WSACleanup();              // Cleaningup winsock
    return 0;
}