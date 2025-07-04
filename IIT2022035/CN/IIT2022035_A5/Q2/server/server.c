/* Devam Desai 
IIT2022035 A5 CN*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SIZE 1024


void send_file(FILE *fp, int sockfd)
{
    char data[SIZE] = {0};

    while(fgets(data, SIZE, fp)!=NULL)
    {
        if(send(sockfd, data, sizeof(data), 0)== -1)
        {
            perror("[-] Error in sending data");
            exit(1);
        }
        bzero(data, SIZE);
    }
}

void serve_request(int new_sock){
    char filename_buff[50];
     recv(new_sock,filename_buff,50,0);
     FILE *fptr;
     fptr = fopen(filename_buff, "r");
     send_file(fptr,new_sock);
     printf("[+]Data sent successfully");
     exit(0);
}

int main ()
{
    char *ip = "127.0.0.1";
    int port = 8080;
    int e;

    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0)
    {
        perror("[-]Error in socket");
        exit(1);
    }
     printf("[+]Server socket created. \n");

     server_addr.sin_family = AF_INET;
     server_addr.sin_port = htons(port);
     server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

     e = bind(sockfd,(struct sockaddr*)&server_addr, sizeof(server_addr));
     if(e<0)
     {
         perror("[-]Error in Binding");
         exit(1);
     }
     printf("[+]Binding Successfull.\n");

     e = listen(sockfd, 10);
     if(e==0)
     {
         printf("[+]Listening...\n");
     }
     else 
     {
         perror("[-]Error in Binding");
         exit(1);
     }
     addr_size = sizeof(new_addr);
     while(1){
        new_sock = accept(sockfd,(struct sockaddr*)&new_addr, &addr_size);
        int pid=fork();
        if(pid==0){
            printf("\nCurrently in process : %d\n",getpid());
            serve_request(new_sock);
        }
        else {
            close(new_sock);
            waitpid(-1,NULL,WNOHANG);
        }
     }
     close(sockfd);
}
