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
#define PORT     6789
#define MAXLINE 1024 
  
// Driver code 
/*int main() { 
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

    cbor item = 
    cbor::map {
        {"sun_x", "18"},
        {"sun_y", "19"},
        {"test_o", "25"}
    };

    cbor::binary data = cbor::encode(item);
      
    int n, len; 
   /* 
   sendto(sockfd, data, data.size(), 
        MSG_CONFIRM, 
        (const struct sockaddr *) &servaddr,  
        sizeof(servaddr)); 
    printf("message sent.\n");

    cbor test = cbor::decode(data);
    test.write(cout);
    std::cout << cbor::debug(test) << endl;*/

    /*std::cout << "DATA2 : " << std::endl;
    std::cout << cbor::debug(data) << std::endl;

    std::cout << "DATA decoded" << std::endl;
    cbor test1(data.data());
    std::cout<< cbor::debug(test1) << std::endl;*/
   /* cbor::string cstring(data);

    cbor test_s(data);
    cbor tttt = cbor::decode(test_s);
    std::cout << cbor::debug(tttt) << std::endl;
    
  
    close(sockfd); 
    return 0; 
} */