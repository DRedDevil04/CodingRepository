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
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %d",ptr->val);
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
			ptr->next=NULL;
		}
		ptr=ptr->next;

	}
	printf("Initial list:\n"); 
	print_list(head,ptr);
	for(ptr=head;ptr->next!=NULL;ptr=ptr->next){
		if(ptr->next->next==NULL){
			last=ptr->next;
		}
		continue;

	}
	struct node *element;
	element=(struct node *)malloc(sizeof(struct node));
	// element->val=11;
	// element->next=NULL;
	// ptr->next=element;
	struct node *head1,*ptr1,*ptr3;
	head1=(struct node *)malloc(sizeof(struct node));
	ptr1=head1;
	for(int i=1;(i<11)&& (ptr1->next==NULL);i++){
		ptr3=(struct node *)malloc(sizeof(struct node));
		ptr1->next=ptr3;
		printf("\nEnter value at node %d: \n",i);
		int number;
		scanf("%d",&number);
		ptr1->val=number;
		if(i==10){
			ptr1->next=NULL;
		}
		ptr1=ptr1->next;
	}
	last->next=head1;

	printf("\n\nList after concatenation:\n");
	print_list(head,ptr);
	printf("\n\nList after deleting first element is:\n");
	element=head;
	head=head->next;
	free(element);
	print_list(head,ptr);
	
	return 0;
}