#include "HttpConnector.h"



HttpConnector::HttpConnector(const char* gethtml, const char* host)
{
	m_req = gethtml;
	m_host = host;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);//Winsock start
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}
}


HttpConnector::~HttpConnector()
{
	//++++++++++add close connection
	closesocket(m_socket);
	WSACleanup();
}

int HttpConnector::SetAddrInfo()
{
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(m_host, "80", &hints, &result);//get  host address settings
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	return 0;
}

int HttpConnector::ConnectToAddr()
{
	m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);//create socket mith host settings

	if (m_socket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	iResult = connect(m_socket, result->ai_addr, result->ai_addrlen);//connect socket and address
	if (iResult == SOCKET_ERROR) {
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(m_socket);
		m_socket = INVALID_SOCKET;
		WSACleanup();
		return 1;
	}

	return 0;
}

int HttpConnector::RecieveFromServer()
{
	do {
		iResult = recv(m_socket, buff, MAX_PACKET_SIZE, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
		for (int i = 0; i < iResult; i++)
		printf("%c", buff[i]);
		// bridge design pattern
	} while (iResult > 0);

	return 0;
}

int HttpConnector::SendToServer()
{
	std::cout << m_req << "\n";
	iResult = send(m_socket, m_req, strlen(m_req), 0);//send GET-request
	printf("Bytes Sent: %ld\n", iResult);
	return 0;
}
