#include <stdio.h>
#include <stdlib.h>
void generate_file(){
	FILE* fptr=fopen("devam_rand_nums.txt","w");
	for(int i=0;i<100;i++){
		fprintf(fptr,"%10d ",rand());
	}
	fclose(fptr);
}


int main(){
	
	generate_file();
	int n;
	int arr[10]={0};
	


	return 0;
}