/*Devam Desai
IIT2022035 Assignment 6 Program 3*/



#include <stdio.h>
void add(int , int);
void get(int);
void average();
int check_entry(int);
int ind=0;
int database[100][2];
int main(){
	
	int flag=1;
	int id,marks;
	for(int i=2;i>0;i--){
		for(int j=100;j>0;j--){
			database[j][i]=0;
		}

	}
	while(flag){
	int option;
	printf("\nEnter Operation you want to perform(Enter 1 for adding, 2 for getting, 3 for getting average, 0 for exiting): \n");
	scanf("%d",&option);
	
	int id,marks;
	switch (option){
	case 1:		
		printf("Enter ID and Marks:\n");
		scanf("%d%d",&id,&marks);
		int check=1;
		while(check){
			if (check_entry(id)){
				printf("Enter ID and Marks(Entered entry already exists):\n");
				scanf("%d%d",&id,&marks);
			}
			else{
				check=0;
			}
		}
		add(id,marks);		
		break;
	case 2:
		printf("Enter ID:\n");
		scanf("%d",&id);
		get(id);
		break;
	case 3:
		average();
		break;
	case 0:
		flag=0;
		break;
	default:
		printf("\nInvalid\n");
		break;

	}
	

}
}
void add(int id,int marks){
	
	database[ind][0]=id;
	database[ind][1]=marks;
	
	ind++;
	
}
void get(int id){
	for(int i=0;i<100;i++){
		if(database[i][0]==id){
			printf("Marks of student id %d are %d\n",id,database[i][1]);
			return;
		}
	}
}
void average(){
	int sum=0;
	for(int i=0;i<=ind;i++){
		sum+=database[i][1];
			
	}
	printf("\nThe Average of marks is: %.2f\n",(float)sum/ind);
}
int check_entry(int id){
	
		for(int j=0;j<100;j++){
			if (database[j][0]==id){
				return 1;
		}

	}
	return 0;
}
