#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "network.hpp"

#define PORT 6789


using namespace std;

Network :: Network()
{
	fromlen = sizeof(addr_client);
	cout<<"Network lancé"<<endl;
}

void Network :: creer_socket()
{
	this->sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	sockaddr_in addr_serveur;
	addr_serveur.sin_addr.s_addr=INADDR_ANY;
	addr_serveur.sin_port = htons(PORT);
	addr_serveur.sin_family= AF_INET; //IPv4
	//Bind the socket with the server address
	int res=bind(sock,reinterpret_cast<sockaddr*>(&addr_serveur),sizeof(addr_serveur));
	if(res!=0)
	{
		//erreur à gérer
	}
}

char* Network::recevoir_donnees()
{
	char* bufferNet;
	bufferNet =  (char*)malloc(sizeof(char)*1024);
	int ret = recvfrom(sock,bufferNet,1024,0,reinterpret_cast<sockaddr*>(&addr_client),&fromlen);
	if(ret<0)
	{
		cout << "erreur de reception..." << endl;
	}
	cout << "buffer network" << bufferNet << endl;
	bufferNet[ret] = '\0';
	return bufferNet;
}

