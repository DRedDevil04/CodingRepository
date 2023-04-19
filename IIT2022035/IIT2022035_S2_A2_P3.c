/*Devam Desai 
IIT2022035 Assignment 2 P2*/
#include <stdio.h>
#include <stdlib.h>
struct player{
	char name[20];
	int runs;
	float avg;
};

int main(){
	int n;
	printf("Enter the number of players:\n");
	scanf("%d",&n);
	struct player* list=(struct player*) malloc (n*sizeof(struct player));
	int max=0;
	int min=0;
	for(int i=0;i<n;i++){
		printf("\nEnter Details of player number %d: ",i+1);
		printf("\nName:");
		scanf("%s",list[i].name);
		printf("\nRuns(integer):");
		scanf("%d",&(list[i].runs));
		printf("\nAverage:");
		scanf("%f",&(list[i].avg));
		if(list[i].avg>list[max].avg){
			max=i;
		}
		if(list[i].avg<list[min].avg){
			min=i;
		}
	}
	printf("\nThe max avg was gotten by");
	for(int i=0;i<n;i++){
		if(list[max].avg==list[i].avg){
			printf("\n%s\n",list[i].name);
		}
	}
	printf("which is %.2f\n\n",list[max].avg);
	printf("\nThe min avg was gotten by");
	for(int i=0;i<n;i++){
		if(list[min].avg==list[i].avg){
			printf("\n%s\n",list[i].name);
		}
	}
	printf("which is %.2f\n\n",list[min].avg);
	return 0;
	
}