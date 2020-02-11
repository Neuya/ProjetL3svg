#include "network.hpp"
#include <iostream>
#include "traitement.hpp"
#include <string>

Traitement::Traitement()
{
	this->net.creer_socket();
}

//Traitements via socket
void Traitement::recvAndModif()
{
	std::string test = net.recevoir_donnees();
	std::cout << test << std::endl;
}