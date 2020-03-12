#include <iostream>
#include <list>
#include <map>
#include "data.hpp"

using namespace std;

Data::Data()
{
	this->mapCourante["sun_x"]="100";
	this->mapCourante["sun_y"]="100";
}

void Data::nextMap()
{
	if(this->listeMap.empty())
	{
		//cout << "ON est la" << endl;
		//printMapCourante();
	}
	else
	{
		//cout << "ON est la" << endl;
		this->mapCourante = this->listeMap.front();
		//printMapCourante();
		this->listeMap.pop_front();
	}
}

void Data::ajouteMapListe(map<string,string> map)
{
	this->listeMap.push_back(map);
}

bool Data::isEmptyListeMap()
{
	return this->listeMap.empty();
}

void Data::printListeMap()
{
	for(list<map<string,string>>::iterator it1=this->listeMap.begin();it1!=this->listeMap.end();it1++)
	{
		cout << "Map : " << endl;
		for(map<string,string>::iterator it2=(*it1).begin();it2!=(*it1).end();it2++)
		{
			cout << it2-> first << "[]" << it2->second << endl;
		}
	}
}

void Data::printMapCourante()
{
	cout << "Map Courante : " << endl;
	for(map<string,string>::iterator it=this->mapCourante.begin();it!=this->mapCourante.end();it++)
	{
		cout << it->first << "[[]]" << it->second << endl;
	}
}