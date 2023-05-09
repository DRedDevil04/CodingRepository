/*Devam Desai
IIT2022035 LA6 P4*/



#include <stdio.h>
#include <stdlib.h>
struct node{
		int val;
		struct node *next;
	};
struct node *end;
void print_list(struct node *head,struct node *ptr){
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %d",ptr->val);
	}
}
void insert(struct node **head,struct node *element){
	
	struct node *ptr=*head;
	end->next=element;
	end=element;
	element->next=NULL;
	
}
int main(){
	
	struct node *head,*ptr,*ptr2;
	head=(struct node *)malloc(sizeof(struct node));
	ptr=head;
	printf("\nEnter first value: \n");
	end=head;
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
			insert(&head,element);
		}
		else{
			break;
		}
	}
	print_list(head,ptr);
	for(int i=0;;i++){
		char c;
		printf("\nDo you want to search new value(y or n)?\n");
		scanf(" %c",&c);
		printf("\n");

		if(c=='y'){
			int num;
			printf("Enter value to search: \n");
			scanf("%d",&num);
			int flag=0;
			struct node * sptr=head;
			struct node * prev=head;
			for(;sptr!=NULL;prev=sptr,sptr=sptr->next){
				if(num==sptr->val){
					printf("\nElement found!\n\nList is now:");
					prev->next = sptr->next;
					sptr->next = head;
					head =sptr;
					flag=1;
					break;
				}
			}
			if(flag){
				print_list(head,ptr);
			}
			else{
				printf("\nSorry! Element not found.\n");
			}
			
		}
		else{
			break;
		}
	}
	printf("\nFinal list is: \n");
	print_list(head,ptr);

	return 0;
}

