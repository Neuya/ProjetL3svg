#ifndef _DATA_HPP
#define _DATA_HPP

#include <map>
#include <list>

using namespace std;

class Data{
public:
	Data();
	map<string,string> mapCourante;
	list<map<string,string>> listeMap;
	void nextMap();
	void ajouteMapListe(std::map<std::string,std::string>); 
	bool isEmptyListeMap();
	void printListeMap();
	void printMapCourante();

};

#endif