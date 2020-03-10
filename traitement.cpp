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
void Traitement::recvAndModif()
{
	char* buffer = net.recevoir_donnees();
	cout<< "buffer : " << buffer << endl;
	map<string,string> mapDrivenValue = constructMapDrivens(buffer);
	/*for(map<string,string>::iterator it=mapDrivenValue.begin();it!=mapDrivenValue.end();it++)
    {
    	cout<<it->first<<" [] "<<it->second<<endl;
    }*/
    free(buffer);
}

map<string,string> Traitement::constructMapDrivens(char* buffer)
{
	vector<unsigned char> dataVect;
	
	int taille = strlen(buffer);
	
	for (int i = 0; i <taille; i++) 
	{
       dataVect.push_back(buffer[i]);
       cout << dataVect[i];
    }

    cout << endl;
    
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
//
    //for(map<string,string>::iterator it=mapReturn.begin();it!=mapReturn.end();it++)
    //{
    //	//cout<<it->first<<" [] "<<it->second<<endl;
    //}

    return mapReturn;
}