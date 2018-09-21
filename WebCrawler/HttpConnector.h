#include <Winsock2.h>
#include <iostream>
#include <ws2tcpip.h>
#include <string>
#include <vector>

#define MAX_PACKET_SIZE 512
#pragma comment (lib, "Ws2_32.lib")
#pragma once
class HttpConnector
{
	WSADATA wsaData;
	int iResult;
	SOCKET m_socket;
	const char* m_req;
	const char* m_host;
	char buff[MAX_PACKET_SIZE];
	addrinfo hints;
	addrinfo *result;

public:
	HttpConnector(const char * req,const char* host);
	~HttpConnector();
	int SetAddrInfo();
	int ConnectToAddr();
	int SendToServer();
	int RecieveFromServer();
};

