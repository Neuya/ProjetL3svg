#include "network.hpp"
#include <iostream>
#include "traitement.hpp"
#include "cbor11.h"
#include <string>

Traitement::Traitement()
{
	this->net.creer_socket();
}

//Traitements via socket
void Traitement::recvAndModif()
{
	std::string test = net.recevoir_donnees();
	cbor item(test);
	cbor data = cbor::encode(item);
	cbor test2(data);
    cbor tttt = cbor::decode(test2);
    std::cout << cbor::debug(tttt) << std::endl;
}