
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
struct message{
    char c;
    int d;
    float f;
};
typedef struct message mess;
int main(void){
    int socket_desc;
    struct sockaddr_in server_addr, client_addr,client_addr2;
    char server_message[100];
    mess client_message;
    int client_struct_length = sizeof(client_addr);
    
   
    memset(server_message, '\0', sizeof(server_message));
    memset(&client_message, '\0', sizeof(client_message));
    
    
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
    
   
    if (recvfrom(socket_desc, &client_message, sizeof(client_message), 0,
         (struct sockaddr*)&client_addr, &client_struct_length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    printf("Received message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    client_message.c++;
    client_message.d++;
    client_message.f++;


    client_addr2.sin_family = AF_INET;
    client_addr2.sin_port = htons(2001);
    client_addr2.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (sendto(socket_desc, &client_message, sizeof(client_message), 0,
         (struct sockaddr*)&client_addr2, client_struct_length) < 0){
        printf("Can't send\n");
        return -1;
    }
    
    close(socket_desc);

}

