/* Devam Desai
IIT2022035 Assignment 11 Program 1*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fptr;
	fptr=fopen("ITP.txt","w");
	fprintf(fptr,"Introduction to Programming");
	return 0;
}