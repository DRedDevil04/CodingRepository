#include <stdio.h>
#include <stdlib.h>
struct node{
		int val;
		struct node *next;
	};

void print_list(struct node *head){
	/*
	prints the list given its head node
	*/
	for(struct node *ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %d",ptr->val);
	}
}
struct node *reverse(struct node *curr,struct node *prev){
	/*
	Reverses the list by taking head as argument in first call, 
	then solving recursively
	*/ 
	
	if(curr->next==NULL){

		curr->next=prev;
		return curr;

	}
	
	struct node *pt=reverse(curr->next,curr);

	if(curr!=prev){

	curr->next=prev;

	}

	else{	
	curr->next=NULL;
	}

	return pt;

}

int main() {
	
	struct node *head,*ptr,*ptr2;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	ptr=head;
	int flag=1;
	//INITIALIZATION OF LIST
	printf("\nEnter positive integers(Enter a negative one to end input):");
	while((ptr->next==NULL)){
		int val;
		scanf("%d",&val);
		if(val>=0){
			
			ptr2=(struct node *)malloc(sizeof(struct node));
			ptr2->next=NULL;
			ptr->next=ptr2;
			ptr->val=val;
			ptr=ptr->next;
			continue;
		}
		else{
			
			ptr->next=NULL;
			break;
		}
	
	}

	for(ptr=head;ptr->next->next!=NULL;ptr=ptr->next){
				
	}
	free(ptr->next);
	ptr->next=NULL;

	//PRINTING INITIAL LIST
	print_list(head);

	//REVERSING THE LIST
	head=reverse(head,head);

	printf("\n\n\n\n");
	//PRINTING THE REVERSED LIST
	print_list(head);
	return 0;
}
