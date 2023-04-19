/*Devam Desai 
IIT2022035 Sem 2 Assignment 1 Program 2*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	
	char *word=(char*)malloc(1000*sizeof(char)); //used malloc because no array notation allowed
	printf("Enter the string: ");
	scanf("%s",word);
	int len=0;
	for(;*(word+len)!='\0';len++){
	}
	printf("\nLength of the string is: %d",len);
	return 0;
}