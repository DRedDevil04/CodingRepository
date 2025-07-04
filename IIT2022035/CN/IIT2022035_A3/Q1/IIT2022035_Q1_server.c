/* Devam Desai 
IIT2022035 A3 CN*/



#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
// #include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> // read(), write(), close()
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main() 
{ 
    int sockfd, connfd, len,new_sockfd; 
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

    
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 

    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 

    FILE * fptr=fopen("./database.txt","r");
    char buff[MAX]; 
    while(1) { // Accept loop.
        int key;
        char buff[50];
        new_sockfd = accept(sockfd, (struct sockaddr *)&cli, &len); 
        if(new_sockfd == -1)
        printf("accepting connection");
        printf("server: got connection from %s port %d\n",
        inet_ntoa(cli.sin_addr), ntohs(cli.sin_port)); 
        char temp_key[50];
        char cur_name[50];
       
        int ct=read(new_sockfd,buff,sizeof(buff));

        
        printf("\n THE KEY RECEIVED IS %s %d\n",buff,ct);
        int flag=0;
        while((fscanf(fptr,"%s %s",temp_key,cur_name))!=EOF){
            
            if(strcmp(temp_key,buff)==0){
                printf("%s %s. %s \n",temp_key,buff,cur_name);
                write(new_sockfd, cur_name, 50); 
                flag=1;
                break;
            }
        }
        if(flag==0) write(new_sockfd,"\nSorry entry not found\n",25);
        rewind(fptr);
        fseek(fptr, 0, SEEK_SET);        
        close(new_sockfd); 
    }



    fclose(fptr);
    close(sockfd); 
}