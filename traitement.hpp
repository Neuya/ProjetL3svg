#ifndef _TRAITEMENT_HPP
#define _TRAITEMENT_HPP

#include "network.hpp"
class Traitement
{
private:
	Network net;
	public:
	Traitement();
	void recvAndModif();
};


#endif