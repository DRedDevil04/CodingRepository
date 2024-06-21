#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
struct packet{
	char c;
	int d;
	float f;

};




int main(){


	int sockfd=socket(PF_INET,SOCK_DGRAM,0);
	
	struct sock_addr host_adr;
	host_adr.sin_port=htons(PORT);
	host_adr.sin_addr=htonl("127.0.0.1");
	
	

	

}
