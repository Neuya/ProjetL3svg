// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <map>
#include <random>
#include <stdint.h>
#include <vector>
#include <chrono>
#include <thread>
#include "cbor11.h"
#define PORT     6789
#define MAXLINE 1024


using namespace std;
// Driver code
int main() {
    int sockfd;
    char buffer[MAXLINE];
    string hello = "Hello from client";
    struct sockaddr_in     servaddr;

    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    int sunX,sunY,houseX,houseY;

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,100);
    //string sunx,suny;

    int j=0;

    while(j < 100)
    {

    sunX = rand() % 100 + 1;
    sunY = rand() % 100 +1;
    houseX = rand() % 100+1;
    houseY = rand() % 100 + 1;


    //cout<< sunX << sunY << endl;

    string sunx = to_string(sunX);
    string suny = to_string(sunY);
    string housex = to_string(houseX);
    string housey = to_string(houseY);

    //cout<< sunx << suny << endl;


    cbor::map data = {
        {"sun_x", sunx},
        {"sun_y", suny},
        {"house_x", housex},
        {"house_y",housey}
    };

    //cout<< cbor::debug(data) << endl;

    cbor::binary encoded = cbor::encode(data);
    //cout << cbor::debug(encoded) << endl;
    std::vector<unsigned char> v = encoded;

    std::vector<unsigned char>::iterator it;

    char* total = new char[v.size()];
    int i=0;
    for(it = v.begin(); it < v.end() ; ++it){
        total[i]=(*it);
        i++;
    }

  //  cout << total << endl;

   sendto(sockfd, total, strlen(total),
        MSG_CONFIRM,
        (const struct sockaddr *) &servaddr,
        sizeof(servaddr));

   /*sendto(sockfd, encoded.data(), encoded.size(),
        MSG_CONFIRM,
        (const struct sockaddr *) &servaddr,
        sizeof(servaddr)); */
    printf("message sent.\n");
    printf("=============\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    j++;
    }
    cout << j << " messages envoyés !" << endl;

    /*std::cout << "DATA2 : " << std::endl;
    std::cout << cbor::debug(data) << std::endl;

    std::cout << "DATA decoded" << std::endl;
    cbor test1(data.data());
    std::cout<< cbor::debug(test1) << std::endl;*/



    close(sockfd);
    return 0;
}
