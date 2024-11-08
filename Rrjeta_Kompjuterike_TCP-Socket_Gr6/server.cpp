#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define SERVER_NAME = ''
#define PORT 8080


int main() {

    
    //Inicializimi i WinStock

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed.\n";
        return 1;
    }



    //Inicializimi i Socket

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket != INVALID_SOCKET) {
        cout << "Server is listening on port 8080 ... \n";
    }else {
        cerr << "Socket creation failed! \n";
        WSACleanup();
        return 1;
    }



    //Bind i Socket
    struct sockaddr_in serverAddress;

    int successfulBind = bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    if (successfulBind == SOCKET_ERROR) {
        cerr << "Bind Failed \n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }



	return 0;
}