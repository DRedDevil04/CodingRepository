#include <stdio.h>
#include <stdlib.h>
void generate_file(){
	FILE* fptr=fopen("devam_rand_nums.txt","w");
	for(int i=0;i<100000;i++){
		fprintf(fptr,"%d ",rand());
	}
	fclose(fptr);
}


int main(){
	
	// generate_file();
	int n;
	int arr[1000]={0};
	FILE* fptr=fopen("devam_nums.txt","r+");
	fseek(fptr,-1,SEEK_END);
	FILE* fst=fopen("devam_nums.txt","r+");
	for(int i=1;fptr!=fst;i++){
		fscanf(fptr,"%d",&n);
		int s;
		fseek(fptr,-1,SEEK_CUR);
		fscanf(fptr,"%d",&s);
		while(s>n){
			fprintf(fptr, "%d ", s);
			fseek(fptr,-1,SEEK_CUR);
			fscanf(fptr,"%d",&s);
			
			
		}
		fprintf(fptr, "%d ", s);
		fprintf(fptr,"%d ",n);
	}
	




	return 0;
}