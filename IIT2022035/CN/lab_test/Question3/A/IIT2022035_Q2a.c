/* Devam Desai
IIT2022035 A2 CN*/

// #include <stdio.h> 
// #include <netdb.h> 
// #include <netinet/in.h> 
// #include <stdlib.h> 
// #include <string.h> 
// #include <sys/socket.h> 
// #include <sys/types.h> 
// #include <unistd.h> // read(), write(), close()
// #define MAX 80 
// #define PORT 8080 
// #define SA struct sockaddr 

// // Function designed for chat between client and server. 
// char func1(int connfd) 
// { 
//     char buff[MAX]; 
//     int n; 
//     char c;
//     // infinite loop for chat 
//     for (;;) { 
//         bzero(buff, MAX); 

//         // read the message from client and copy it in buffer 
//         read(connfd, buff, sizeof(buff)); 
//         // print buffer which contains the client contents 
//         printf("From client 1: %s\t", buff); 
        
//         n = 0; 
//         // copy server message in the buffer 
        

//         // and send that buffer to client 
//         // write(connfd, "Received character", sizeof(buff)); 

//         // if msg contains "Exit" then server exit and chat ended. 
        
//         return buff[0];
//     } 
// } 
// void func2(int connfd,char c) 
// { 
//     char buff[MAX]; 
//     int n; 
    
//     // infinite loop for chat 
//     for (;;) { 
//         bzero(buff, MAX); 
//         buff[0]=c+1;
        
        

//         // and send that buffer to client 
//         write(connfd, buff, sizeof(buff)); 

//         // if msg contains "Exit" then server exit and chat ended. 
        
//     } 
// } 

// // Driver function 
// int main() 
// { 
//     int sockfd, connfd, len; 
//     struct sockaddr_in servaddr, cli; 

//     // socket create and verification 
//     struct sockaddr_in address;
//     address.sin_family = AF_INET; 
//     address.sin_addr.s_addr = htonl(INADDR_ANY); 
//     address.sin_port = htons(8080); 
//     // socket create and verification 
//     sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
//     if((bind(sockfd, (struct sockaddr *)&address, sizeof(address)))==-1){
//         printf("\nError in binding\n");
//     }
    
//     if (sockfd == -1) { 
//         printf("socket creation failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("Socket successfully created..\n"); 
//     bzero(&servaddr, sizeof(servaddr)); 

//     // assign IP, PORT 
//     servaddr.sin_family = AF_INET; 
//     servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
//     servaddr.sin_port = htons(PORT); 
//     char buff[80];
//     // Binding newly created socket to given IP and verification 
//     int size_cli;
//     if(recvfrom(connfd,buff,80,0,(SA* )&cli,(socklen_t *)&size_cli

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
int main(){

    int socket_desc;
    struct sockaddr_in server_addr, client_addr,client_addr2;
    char server_message[100], client_message[100];
    int client_struct_length = sizeof(client_addr);
   

 
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
   				 

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socket_desc < 0){
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");







    
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
 
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");
    
    printf("Listening for incoming messages...\n\n");
    
   
    if (recvfrom(socket_desc, client_message, sizeof(client_message), 0,
         (struct sockaddr*)&client_addr, &client_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    printf("Received message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    printf("Msg from client: %s\n", client_message);
    

    for(int i = 0; client_message[i]; ++i)
        client_message[i] = (client_message[i]);

    strcpy(server_message, client_message);

    server_message[0]+=1;


    client_addr2.sin_family = AF_INET;
    client_addr2.sin_port = htons(2001);
    client_addr2.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (sendto(socket_desc, server_message, strlen(server_message), 0,
         (struct sockaddr*)&client_addr2, client_struct_length) < 0){
        printf("Can't send\n");
        return -1;
    }
    
    // Close the socket:
    close(socket_desc);

}

