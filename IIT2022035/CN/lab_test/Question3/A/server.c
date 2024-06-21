#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 8080


int main(){

	int socketfd=socket(PF_INET, SOCK_DGRAM, 0 );
	struct sock_addr serv_adr;
	serv_adr.sin_port=PORT;
	serv_adr.sin_addr=htonl(INADDR_ANY);
	serv_adr.sin_family=AF_INET;

	if(bind(socketfd,&serv_adr,sizeof(serv_adr))){
		
	}	
	else{
		printf("Error in binding");
	}
	
	
}
