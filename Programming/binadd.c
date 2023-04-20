#include <stdio.h>
int main(){
	char bin1[8],bin2[8];
	int arr1[8],arr2[8];
	printf("Enter:");
	scanf("%s",bin1);
	for(int i=0;i<8;i++ ){
		arr1[7-i]=bin1[i]-'0';
	}
	printf("Enter:");
	scanf("%s",bin2);
	for(int i=0;i<8;i++ ){
		arr2[7-i]=bin2[i]-'0';
	}
	int carry=0,sum[8];
	for(int i=0;i<=7;i++){
		sum[i]=((arr1[i]^arr2[i])^carry);
		carry=(((arr1[i]^arr2[i])&carry)| (arr1[i]&arr2[i]));
	}
	printf("\n");
	for(int i=0;i<8;i++ ){
		printf("%d",sum[7-i]);
	}	
	printf("\n");
	return 0;

}