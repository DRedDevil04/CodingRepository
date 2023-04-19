/*Devam Desai
IIT2022035 Assignment 11 Program 5*/

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
	for(int i=1;(i<11)&& (ptr->next==NULL);i++){
		ptr2=(struct node *)malloc(sizeof(struct node));
		ptr->next=ptr2;
		ptr->val=i;
		if(i==10){
			ptr->next=NULL;
		}
		ptr=ptr->next;
	}
	printf("Initial list:\n");
	print_list(head,ptr);
	for(ptr=head;ptr->next!=NULL;ptr=ptr->next){
		continue;
	}
	struct node *element;
	element=(struct node *)malloc(sizeof(struct node));
	element->val=11;
	element->next=NULL;
	ptr->next=element;
	printf("\n\nList after adding element:\n");
	print_list(head,ptr);
	printf("\n\nList after deleting first element is:\n");
	element=head;
	head=head->next;
	free(element);
	print_list(head,ptr);
	
	return 0;
}