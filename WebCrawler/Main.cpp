#include "HttpConnector.h"
#include<string>



int main() {
	
	std::string gethtml = "GET / HTTP/1.1\r\n";
	gethtml += "Host: www.alkcarb.myspecies.info \r\n";
	gethtml += "Connection: close\r\n";
	gethtml += "Accept-Language: fr,fr-fr;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
	gethtml += "\r\n";

	HttpConnector a(gethtml.c_str(),"www.alkcarb.myspecies.info");
	a.SetAddrInfo();
	a.ConnectToAddr();
	a.SendToServer();
	a.RecieveFromServer();
	return 0;
}