/*Devam Desai
IIT2022035 Queue implementation via linked list*/

#include <stdio.h>
#include <stdlib.h>
struct node{
	double val;
	struct node *next;
};
typedef struct node element ;
void print_list(element *head){
	element* ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %lf",ptr->val);
	}
}
element* pop(element **head){
	element* ptr=*head,*prev=*head;
	for(;ptr->next!=NULL;ptr=ptr->next){
		prev=ptr;
		continue;
	}
	prev->next=NULL;

	return ptr;
}
void push(element ** head , element *to_push){
	if(*head==to_push){
		return;
	}
	
	to_push->next=*head;
	*head=to_push;
	return;

}

int main(){
	element* queue;
	int op=1;
	int i=0;
	while(op){
		printf("\nDo you want to push or pop?(0 for quit, 1 for push and 2 for pop)\n");
		scanf("%d",&op);
		
		if(op==1){
			element *to_push=(element *)malloc(sizeof(element));
			printf("\nEnter the number you want to insert: ");
			scanf("%lf",&(to_push->val));
			to_push->next=NULL;
			if(i==0){
				push(&to_push,to_push);
				i++;
				queue=to_push;
				// print_list(queue);
				continue;
			}
			
			push(&queue,to_push);
			// print_list(queue);
			i++;
		}
		else if(op==2){
			
			if(i==0){
				printf("Sorry! No element inserted in queue to pop. Try again!");
				continue;
			}
			element* popped=pop(&queue);
			i--;
			printf("The value in the popped element is %f",popped->val);
			free(popped);
		}
		else continue;

	}



	return 0;
}