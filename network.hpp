#ifndef _NETWORK_HPP
#define _NETWORK_HPP


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "network.hpp"

#define PORT 6789

class Network{
private:
	sockaddr_in addr_client;
	socklen_t fromlen;
	int sock;
	char buffer[1500];
public:
	Network();
	void creer_socket();
	std::string recevoir_donnees();
};

#endif