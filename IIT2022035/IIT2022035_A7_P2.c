/*Devam Desai
IIT2022035 Assignment_7 Program_2*/


#include <stdio.h>
int gx(int);
int fx(int);
int pow_2(int);
int main(){
	int x;
	printf("Enter input x for f: ");
	scanf("%d",&x);
	printf("\nOutput is %d",fx(x));
	return 0;
}
int gx(int x){
	if(x==1){
		return 6;

	}
	else if(x>1){
		return (4*(gx(x/2))+x);
	}
}
int fx(int x){
	long long m=1e9+7;
	return ((gx(pow_2(x))%m));
}
int pow_2(int x){
	int exp=1;
	while(x--){
		exp*=2;
	}
	return exp;
}