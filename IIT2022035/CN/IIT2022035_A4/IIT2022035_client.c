/* Devam Desai
IIT2022035 A2 CN*/



#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8086
#define SA struct sockaddr
void func(int sockfd)
{
    
    int n;
    int pid=fork();
    if(pid==0){
        char buff[MAX];
        for (;;) {
            bzero(buff, sizeof(buff));
            n = 0;
            while ((buff[n++] = getchar()) != '\n')
                ;
            write(sockfd, buff, sizeof(buff));  
            if ((strncmp(buff, "exit", 4)) == 0) {
                printf("Client Exit...\n");
                kill(pid,SIGKILL);
                exit(0);
            }
        }   
    }
    else{
        char buff[MAX];
        for (;;) {
            bzero(buff, sizeof(buff));
            read(sockfd, buff, sizeof(buff));
            printf("You received a new message: %s", buff);
            if ((strncmp(buff, "exit", 4)) == 0) {
                printf("Client Exit...\n");
                kill(pid,SIGKILL);
                exit(0);
            }
        }
    }
    
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.156.248");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}
