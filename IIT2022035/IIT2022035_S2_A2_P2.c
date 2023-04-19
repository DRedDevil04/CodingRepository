/*Devam Desai 
IIT2022035 Assignment 2 P2*/
#include <stdio.h>
#include <stdlib.h>
struct student{
	char name[20];
	int rollno;
	float cgpa;
};

int main(){
	int n;
	printf("Enter the number of students:\n");
	scanf("%d",&n);
	struct student* list=(struct student*) malloc (n*sizeof(struct student));
	int max=0;
	int min=0;
	for(int i=0;i<n;i++){
		printf("\nEnter Details of student number %d: ",i+1);
		printf("\nName:");
		scanf("%s",list[i].name);
		printf("\nRollNumber(integer):");
		scanf("%d",&(list[i].rollno));
		printf("\nCGPA:");
		scanf("%f",&(list[i].cgpa));
		if(list[i].cgpa>list[max].cgpa){
			max=i;
		}
		if(list[i].cgpa<list[min].cgpa){
			min=i;
		}
	}
	printf("\nThe max CGPA was gotten by");
	for(int i=0;i<n;i++){
		if(list[max].cgpa==list[i].cgpa){
			printf("\n%s\n",list[i].name);
		}
	}
	printf("which is %.2f\n\n",list[max].cgpa);
	printf("\nThe min CGPA was gotten by");
	for(int i=0;i<n;i++){
		if(list[min].cgpa==list[i].cgpa){
			printf("\n%s\n",list[i].name);
		}
	}
	printf("which is %.2f\n\n",list[min].cgpa);
	return 0;
	
}