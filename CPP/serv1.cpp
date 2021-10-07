// Contributer: Kritik Agarwal <https://github.com/Kritik007>

// Compile using cmd: g++ serv1.cpp -o serv1 -lwsock32 -lws2_32

// Using TCP/IP sockets, write a client server program to say hello to each other or echo the message.

#include <bits/stdc++.h>
#include <winsock2.h>
#include <ws2tcpip.h>

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
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        cerr << "<!> Can't create a socket!! quitting..." << endl;
        return 0;
    }
    // Binding the socket to an ipaddress and port
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(listening, (struct sockaddr *)&hint, sizeof(hint));
    listen(listening, SOMAXCONN); // Telling Winsock that Socket is Listening
    // Waiting for client connection
    sockaddr_in client;
    int clientSize = sizeof(client);
    SOCKET clientSocket = accept(listening, (struct sockaddr *)&client, &clientSize);
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
        cout << "<~> " << host << " connected on port " << service << endl;
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << "<~> " << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
    closesocket(listening); // closing listening socket
    // Accepting and echoing msg back to client
    char buf[4096];
    while (true)
    {
        ZeroMemory(buf, 4096);
        // waiting for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            cerr << "<!> Error in recv(). quitting..." << endl;
            break;
        }
        if (bytesReceived == 0)
        {
            cout << "\n<!> Client Disconnected <!>" << endl;
            break;
        }

        cout << "CLIENT> " << string(buf, 0, bytesReceived) << endl;
        //echoing msg back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }
    closesocket(clientSocket); // closing the socket
    WSACleanup();              // cleaningup winsock
    return 0;
}