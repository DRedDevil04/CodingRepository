// #include "./devam_protocol.h"



int ddreq_send(int sockfd,char *message,int size,int type){
	// Sends a dd packet
	ddreq_packet pacAddr=(ddreq_packet) malloc(size*sizeof(char)+4);
	pacAddr="";

	if(type==0){
		//indicates number
		strcat(pacAddr,NUM);
	}
	else{
		//indicates name
		strcat(pacAddr,NAME);
	}
	strcat(pacAddr,message);
	strcat(pacAddr,);
	return send(sockfd,pacAddr,sizeof(size*sizeof(char)+4),0);
}



int getReqType(ddreq_packet message){
	// returns 0 for num, 1 for name
	if(message[0]==NUM) return 0;
	else return 1;
}
// int getReqData(ddreq_packet packet, char *buff,int size){
// 	int ct=0;
// 	while(packet[1+ct]!=ETR && ct<size-2){
// 		buff[ct]=packet[ct+1];
// 	}
// 	return ct;
// }





// int ddreq_recvAP(int sockfd,char *message,int type){


// 	//Function return 1 "NUM" if number is received and 9 "NAME" if name is received
// 	ddreq_packet pac=*pacAddr;
// 	int ret_val=recv(sockfd,(ddreq_packet *)pacAddr,sizeof(ddreq_packet),0);
// 	if((*pacAddr).req_code == NAME ){
// 		printf("\nData Received: %s\n",(*pacAddr).val.name);
// 		return NAME ;
// 	}
// 	else{
// 		printf("\nData Received: %s\n",(*pacAddr).val.num);
// 		return NUM;
// 	}

// }

// int ddres_send(int sockfd,char *message,int size){
// 	ddres_packet pacAddr=(ddreq_packet) malloc(size*sizeof(char)+2);
// 	pacAddr="";

// 	strcat(pacAddr,message);
// 	strcat(pacAddr,ETR);
// 	return send(sockfd,(ddres_packet *)pacAddr,sizeof(size*sizeof(char)+2),0);
// }
// int ddres_recvAP(int sockfd,ddres_packet *pacAddr){
// 	//Function return 1 "NUM" if number is received and 9 "NAME" if name is received
// 	ddres_packet pac=*pacAddr;
// 	int ret_val=recv(sockfd,(ddres_packet *)pacAddr,sizeof(ddres_packet),0);
// 	if((*pacAddr).req_code == NAME ){
// 		printf("\nData Received: %s\n",(*pacAddr).val.name);
// 		return NAME;
// 	}
// 	else{
// 		printf("\nData Received: %s\n",(*pacAddr).val.num);
// 		return NUM;
// 	}
// }

