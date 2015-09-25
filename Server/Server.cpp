//TCP SERVER
#pragma comment(lib,"ws2_32.lib")
#include <cstdio>
#include <iostream>
#include <WinSock2.h>// sollte immer vor Windows.h und nach cstdio eingebunden werden
#include <Windows.h>

using namespace std;

int main()
{
	//Hilfsvariable
	long res;

	//Versionsdaten
	WSADATA wsaData;

	//ws2_32.dll Aktivieren

	res = WSAStartup(MAKEWORD(2,0),&wsaData); //inizialisiere WSA
	if (res == 0)
		printf("WSA Start () \t\t erfolgreich");
	else
		printf("error WSA Start(): ",WSAGetLastError());

	//Socket Deskriptoren
	SOCKET slisten, client;

	//Socket anfordern bzw. Kommunikationsendpunkt einrichten
	slisten = socket(AF_INET,SOCK_STREAM,0); //Richte verbindung ein mit AF_INET \ AF_INET6 für ipv4 oder ipv6
	if (slisten!=INVALID_SOCKET)
		printf("Socket() \t\t erfolgreich");
	else
		printf("error socket(): ",WSAGetLastError());


	//Verbindungsinformationen

	sockaddr_in info;
	info.sin_addr.s_addr = inet_addr("127.0.0.1");//vergebe server Ip
	info.sin_family = AF_INET;// sage mit welchem protokoll
	info.sin_port = htons(52525);//Bestimme Port
	int infoleng = sizeof(info);//ermitle größe von info

	//Binde Port
	res = bind(slisten, (struct sockaddr*)&info, infoleng);
	if (res != SOCKET_ERROR)
		printf("Portbindung() \t\t erfolgreich");
	else
		printf("error Portbindung(): ", WSAGetLastError());

	//Erstelle Warteliste für ankommende verbindungen

	res = listen(slisten,SOMAXCONN);
	if (res!=SOCKET_ERROR)
		printf("Wartelisten() \t\t erfolgreich");
	else
		printf("error Wartelisten(): ", WSAGetLastError());


	//Hole Client informationen

	sockaddr_in clientInfo; //hole infos

	int clientInfoHolen = sizeof(clientInfo);//Hole größe der Infos

	while (1)
	{

		client = accept(slisten,(struct sockaddr*) &clientInfo,&clientInfoHolen);//socket descriptor initialisiert
		if (client != SOCKET_ERROR)//prüfe ob Client Port passt
			printf("Client akzeptiert: ",inet_ntoa(clientInfo.sin_addr));//hole client Ip
		    printf(": \n",clientInfo.sin_port);//Hole Client Port


			res = send(client,"Server nachricht erhalten",strlen("Server nachricht erhalten"),0);//erste nachricht an den Client
			if (res == SOCKET_ERROR)
				printf("error beim versenden");

	}
	closesocket(client); //Freigabe Client
	closesocket(slisten);//Freigabe Server
	WSACleanup();//freigabe WSA
	return 0;
}
