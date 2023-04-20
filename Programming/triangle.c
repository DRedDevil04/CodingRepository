#include <stdio.h>
int main(){
	int count=1;
	char c='A';
	for(int i=1;i<=5;i++){
		for(int j=5-i-1;j>=0;j--){
			printf(" ");
			}
		for(int j=1;j<=i;j++){
			if(i%2==1){
				printf("%d ",count++);
			}
			else{
				printf("%c ",c++);
			}
		}
		printf("\n");
		}
	
	return 0;
}
