
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
int main(){



    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[100];
    mess client_message;
    int server_struct_length = sizeof(server_addr);
    
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
    
    printf("Enter char: ");
    scanf("%c",&(client_message.c));
    printf("Enter int: ");
    scanf("%d",&(client_message.d));
    printf("Enter float: ");
    scanf("%f",&(client_message.f));


    if(sendto(socket_desc, &client_message, sizeof(client_message), 0,
         (struct sockaddr*)&server_addr, server_struct_length) < 0){
        printf("Unable to send message\n");
        return -1;
    }
    
    if(recvfrom(socket_desc, server_message, sizeof(server_message), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
    
    printf("Server's response: %s\n", server_message);
    
    close(socket_desc);
    
    return 0;
}


