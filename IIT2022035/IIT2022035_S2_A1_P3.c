/*Devam Desai 
IIT2022035 Sem 2 Assignment 1 Program 3*/
#include <stdio.h>
int *download_time(int size,int speed){
	static int times[3];
	int time=(size/speed); //intentionally floored
	times[0]=time/(60*60);
	time%=(60*60);
	times[1]=time/(60);
	time%=(60);
	times[2]=time;
	return times;
}
int main(){
	int speed,size;
	printf("Enter File Size:\n");
	scanf("%d",&size);
	printf("Enter Download Speed:\n");
	scanf("%d",&speed);
	

	int *times=download_time(size,speed);

	printf("\nTime is:\nHours:%d\nMinutes:%d\nSeconds:%d\n",*(times),*(times+1),*(times+2));


	return 0;
}