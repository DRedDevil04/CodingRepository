/* Devam Desai
IIT2022035 Assignment 11 Program 2*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	FILE *fptr;
	fptr=fopen(argv[1],"a+");
	char c;
	printf("Enter text(enter eof(ctrl d(linux) and ctrl z(for windows)) for ending):");
	while((c=getchar())!=EOF){
		fprintf(fptr,"%c",c);
	}
	char line[1000];
	fseek(fptr,0,SEEK_SET);
	printf("\n");
	while(fgets(line,1000,fptr)!=NULL){
		printf("%s",line);
	}
	return 0;
}