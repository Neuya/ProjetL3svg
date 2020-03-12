#include "network.hpp"
#include <iostream>
#include "traitement.hpp"
#include "cbor11.h"
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

Traitement::Traitement()
{
	this->net.creer_socket();
}


//Traitements via socket
void Traitement::recvDataAndStockMap(Data* d)
{
	char* buffer = net.recevoir_donnees();
	d->ajouteMapListe(constructMapDrivens(buffer));
	//cout << "EMPTY " << d->isEmptyListeMap() << endl;
	//d->printListeMap();
    free(buffer);
}

map<string,string> Traitement::constructMapDrivens(char* buffer)
{
	vector<unsigned char> dataVect;
	
	int taille = strlen(buffer);
	
	for (int i = 0; i <taille; i++) 
	{
       dataVect.push_back(buffer[i]);
    }
    
    cbor::binary decoded = dataVect;
    cbor decodedItem = cbor::decode(decoded);
    
    if(!decodedItem.is_map())
    {
    	cout<<"doit etre une map"<<endl;
    }

    map<cbor,cbor> mapDecode = decodedItem;

    map<cbor,cbor>::iterator it = mapDecode.begin();
    map<string,string> mapReturn;

    while(it != mapDecode.end())
    {
    	string it1 = it->first;
    	string it2 = it->second;
    	mapReturn[it1]  =  it2;
    	it++;
    }

    return mapReturn;
}



