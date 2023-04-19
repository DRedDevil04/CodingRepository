/* Devam Desai
IIT2022035 Assignment 11 Program 4*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct node{
		int val;
		struct node *next;
	};
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
	
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %d",ptr->val);
	}
	return 0;
}