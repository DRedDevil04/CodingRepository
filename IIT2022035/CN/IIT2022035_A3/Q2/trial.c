#include<stdio.h>
#include<stdlib.h>
#include "./devam_protocol.h"

int main(){
	char mess[]="\x01 AAAA\x03";
	printf("\n%d\n",sizeof(char));
	char buff[50];
	getReqData((ddreq_packet)mess,buff,50);
	printf("\n%s\n",buff);
	packet_check("DEVAM",18,1);
	return 0;
}