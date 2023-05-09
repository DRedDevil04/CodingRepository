#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int n;
	printf("Enter length of array: ");
	scanf("%d",&n);
	// int *arr=(int *)malloc(sizeof(int)*n);
	int count[100]={0};
	printf("\nEnter the array: ");
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		count[num]++;
	}
	printf("\n\n\n\n____________________________SORTED ARRAY_____________________________\n\n\n\n");
	for(int i=0;i<=99;i++){
		while(count[i]--){
			printf("%d ",i);
		}
	}
	printf("\n\n\n\n");


	return 0;
}