//TCP CLIENT

#pragma comment(lib,"ws2_32.lib")
#include <cstdio>
#include <iostream>
#include <WinSock2.h>// sollte immer vor Windows.h und nach cstdio eingebunden werden
#include <Windows.h>

using namespace std;

int main()
{

	//Hilfsvariable
	long rs;

	//Versionsdaten
	WSADATA wsaData;
	//Socket Deskriptoren
	SOCKET sConnect;

	sockaddr_in conPar;//verbindungsparameter

	//ws2_32.dll Aktivieren

	rs = WSAStartup(MAKEWORD(2, 0), &wsaData); //inizialisiere WSA
	if (rs == 0)
		printf("WSA Start () \t\t erfolgreich");
	else
		printf("error WSA Start(): ", WSAGetLastError());

	//Socket anfordern bzw. Kommunikationsendpunkt einrichten

	sConnect = socket(AF_INET, SOCK_STREAM, 0); //Richte verbindung ein mit AF_INET \ AF_INET6 für ipv4 oder ipv6
	if (rs != INVALID_SOCKET)
		printf("Socket() \t\t erfolgreich");
	else
		printf("error socket(): ", WSAGetLastError());

	return 0;
}