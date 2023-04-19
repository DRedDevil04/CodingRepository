/*Devam Desai
IIT2022035 Assignment 8 Program 3*/
#include <stdio.h>
void print_gareeb();
void ameer_ko_aur_ameer();
struct customer{
	char name[100];
	unsigned long long int acc_num;
	float balance;
} Database[5];

int main(){
	int i=0;

	while(i<5){
		printf("\nEnter Name of Customer %d:",i+1);
		scanf("%s",Database[i].name);
		printf("\nEnter Account number and Balance: ");
		scanf("%llu%f",&Database[i].acc_num,&Database[i].balance);
		i++;
	}
	print_gareeb();
	ameer_ko_aur_ameer();
	return 0;
}
void print_gareeb(){
	for(int i=0;i<5;i++){
		if(Database[i].balance<=100){
			printf("\n%s has balance less than $100",Database[i].name);
		}
	}
}
void ameer_ko_aur_ameer(){
	for(int i=0;i<5;i++){
		if(Database[i].balance>=1000){
			Database[i].balance+=100;
			printf("\n%s now has balance %.2f",Database[i].name,Database[i].balance);
		}
	}
}