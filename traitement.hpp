#ifndef _TRAITEMENT_HPP
#define _TRAITEMENT_HPP

#include "network.hpp"
#include <map>
#include <string>
class Traitement
{
private:
	Network net;
	public:
	Traitement();
	void recvAndModif();
	std::map<std::string,std::string> constructMapDrivens(char*);
};


#endif