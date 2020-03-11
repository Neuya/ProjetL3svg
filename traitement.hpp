#ifndef _TRAITEMENT_HPP
#define _TRAITEMENT_HPP

#include "network.hpp"
#include "data.hpp"
#include <map>
#include <list>
#include <string>
class Traitement
{
private:
	Network net;
	/*std::map<std::string,std::string> mapCourante;
	std::list<std::map<std::string,std::string>> listeMap;*/

public:
	Traitement();
	void recvDataAndStockMap(Data*);
	std::map<std::string,std::string> constructMapDrivens(char*);
	/*void ajouteMapListe(std::map<std::string,std::string>);
	void nextMap();
	std::map<std::string,std::string> getMapCourante();
	void printListeMap();
	void printMapCourante();*/
};


#endif