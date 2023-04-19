/*Devam Desai
IIT2022035 
Semester 2
Assignment 3 Program 1*/

#include <stdio.h>
#include <stdlib.h>
struct node{
		int val;
		struct node *next;
	};
void print_list(struct node *head,struct node *ptr){
	int i=0;
	for(ptr=head;ptr!=head||i==0;ptr=ptr->next){
		printf("\nElement is %d",ptr->val);
		i=1;
	}
}
int main(){
	
	struct node *head,*ptr,*ptr2;
	head=(struct node *)malloc(sizeof(struct node));
	ptr=head;
	struct node *last;
	for(int i=1;(i<11)&& (ptr->next==NULL);i++){
		ptr2=(struct node *)malloc(sizeof(struct node));
		ptr->next=ptr2;
		printf("Enter value at node %d: \n",i);
		int number;
		scanf("%d",&number);
		ptr->val=number;
		if(i==10){
			ptr->next=head;

		}
		ptr=ptr->next;

	}
	
	print_list(head,ptr);
	
	return 0;
}