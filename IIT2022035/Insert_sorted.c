/*Devam Desai
IIT2022035 
Semester 2
Assignment 3 Program 2*/

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
void insert_sorted(struct node **head,struct node *element){

	struct node *ptr=*head;
	struct node *prev=*head;
	for(;;ptr=ptr->next){

		if(prev==*head && (ptr->val)>(element->val) && ptr==*head){

				element->next=&(**head);
				*head=element;
				return;

			}
		if((ptr->val)<=(element->val)){
			
			if(ptr->next==NULL){

				ptr->next=element;
				element->next=NULL;
				return;

			}

			prev=ptr;
			continue;

		}
		else{

			prev->next=element;
			element->next=ptr;
			return;

		}

	}
	
}
int main(){
	
	struct node *head,*ptr,*ptr2;
	head=(struct node *)malloc(sizeof(struct node));
	ptr=head;
	printf("\nEnter first value: \n");
	scanf("%d",&(head->val));
	struct node element;
	for(int i=0;;i++){
		char c;
		printf("Do you want to enter new value(y or n)?\n");
		scanf(" %c",&c);
		printf("\n");
		if(c=='y'){
			struct node *element=(struct node *)malloc(sizeof(struct node));
			element->next=NULL;

			printf("Enter value: \n");
			scanf("%d",&(element->val));
			insert_sorted(&head,element);
		}
		else{
			break;
		}
	}
	print_list(head,ptr);
	return 0;
}

	
	