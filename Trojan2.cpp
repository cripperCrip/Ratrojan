// Trojan2.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"


using namespace Trojan2;
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}

bool connect(std::string Ip, std::string Port, SOCKET& ConnectedSocket, WSADATA& wsaData)
{
	bool connectionResult = true;
	char message[1500];
	int iResult;
	struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
	PCSTR pcstrIP = const_cast <char *> (Ip.c_str());
	PCSTR pcstrPort = const_cast <char *> (Port.c_str());

	ConnectedSocket = INVALID_SOCKET;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
		sprintf_s(message, "WSAStartup failed with error: %d\n", iResult);
		System::String^ sMessage = gcnew String (message);
		MessageBox::Show(sMessage);
        return false;
    }

	ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
    iResult = getaddrinfo(pcstrIP, pcstrPort, &hints, &result);
    if ( iResult != 0 ) 
	{
		sprintf_s(message, "Getaddrinfo failed with error: %d\n", iResult);
		System::String^ sMessage = gcnew String (message);
		MessageBox::Show(sMessage);
        WSACleanup();
        return false;
    }

	// Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectedSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (ConnectedSocket == INVALID_SOCKET) 
		{
			sprintf_s(message, "socket failed with error: %ld\n", WSAGetLastError());
			System::String^ sMessage = gcnew String (message);
			MessageBox::Show(sMessage);
            WSACleanup();
            return false;
        }

        // Connect to server.
        iResult = connect( ConnectedSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) 
		{
            closesocket(ConnectedSocket);
            ConnectedSocket = INVALID_SOCKET;
            continue;
        }

        break;
    }

	freeaddrinfo(result);

    if (ConnectedSocket == INVALID_SOCKET) 
	{
		sprintf_s(message, "Unable to connect to Ip: %s - Port: %s", Ip.c_str(), Port.c_str());
		System::String^ sMessage = gcnew String (message);
		MessageBox::Show(sMessage);
        WSACleanup();
        return false;
    }

	return connectionResult;
}

bool disconnect(SOCKET connectedSocket, WSADATA wsaData)
{
	bool disconnectResult = true;
	
	closesocket(connectedSocket);
	WSACleanup();

	return disconnectResult;
}

bool send(SOCKET connectedSocket, int option, System::String^ Message)
{
	bool sendResult = true;
	int iResult;
	char sendbuf[1024];
	char recvbuf[1024];
	int recvbuflen = 1024;

	std::string sMessage = msclr::interop::marshal_as<std::string>(Message);

	sprintf_s(sendbuf, "%d;%s\0", option, sMessage.c_str());

	//char recvbuf[512];
	//int lenRecvBuf = 512;

	 // Send an initial buffer
    iResult = send( connectedSocket, sendbuf, (int)strlen(sendbuf), 0 );

    if (iResult == SOCKET_ERROR)
	{
        //printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(connectedSocket);
        WSACleanup();
        return false;
    }

	 // shutdown the connection since no more data will be sent
    /*iResult = shutdown(connectedSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(connectedSocket);
        WSACleanup();
        return false;
    }*/

    iResult = recv(connectedSocket, recvbuf, recvbuflen, 0);
    if ( iResult > 0 )
	{
		if (strcmp(recvbuf, "OK"))
		{
			return false;
		}
	}
    else if ( iResult == 0 )
	{
        return false;
	}
    else
	{
        return false;
	}

	return sendResult;
}
