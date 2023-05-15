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
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print_list(struct node *head){
	struct node *ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\n--> %d",ptr->val);
	}
}
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
void insert(struct node **head,struct node *element){
	if(*head==NULL){
		*head =element;
		element->next=NULL;
		return;
	}
	struct node *ptr=*head;
	struct node *prev=*head;
	for(;;ptr=ptr->next){

		if(ptr->next==NULL){
			ptr->next=element;
			element->next = NULL;
			return ;
		}
	}
	
}
void free_list(struct node** ptr)
{
   /* deref head_ref to get the real head */
   struct node* current = *ptr;
   struct node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *ptr= NULL;
}
void delete_tail(struct node **head){
	if((*head)->next==NULL){
		struct node *t1=*head;
		*head=NULL;
		free(t1);
		return;
	}
	struct node * ptr=*head;
	struct node * prev=*head;
	for(;ptr->next!=NULL;ptr=ptr->next){
		prev=ptr;
		continue;
	}
	prev->next=NULL;
	free(ptr);

}


void permutation(int chosen[], int a[],struct node **head, int r,int size)
{  
	// printf("\nArr is : ");
	// printArr(a,r);
	// printf("\n");
    if (size == r) {
    	printf("\n\n");
        print_list(*head);
        // delete_tail(head);
        return;
    } 
    for (int i = 0; i < r; i++) {
        if(chosen[i]){
        	continue;
        }
        chosen[i]=1;
        struct node * ele=(struct node *)malloc(sizeof(struct node ));
        ele->next=NULL;
        ele->val=a[i];
        insert(head,ele);
        permutation(chosen,a,head,r,size+1);
        delete_tail(head);
        chosen[i]=0;

    }
}
void subset_generate(int * arr, int n,int r,struct node ** head,int i,int size){
	if(i>n){
		return;
	}
	if(size >r){
		return;
	}
	if(size==r){
		int *siu=(int *)malloc(sizeof(int)*r);
		int *siu2=(int *)malloc(sizeof(int)*r);
		struct node *hed=NULL;
		for(int i=0;i<r;i++){
			siu[i]=0;
		}
		struct node * ptr=*head;
		int i=0;
		for(;ptr!=NULL;ptr=ptr->next,i++){
			siu2[i]=ptr->val;
		}
		printf("\n\nThe Permutations are:\n");
		permutation(siu,siu2,&hed,r,0);
		free_list(&hed);
		// print_list(*head);
		return;
	}
	subset_generate(arr,n,r,head,i+1,size);
	struct node *ele=(struct node *)malloc(sizeof(struct node));
	ele->next=NULL;
	ele->val=arr[i];
	insert(head,ele);
	subset_generate(arr,n,r,head,i+1,size+1);
	delete_tail(head);

}
int main(){
	
	struct node *head,*ptr,*ptr2;
	head=NULL;
	ptr=head;
	int n;
	printf("\nenter number of values in set: ");
	scanf("%d",&n);
	int * arr= (int *)malloc(sizeof(int));
	for(int i=0;i<n;i++){
		printf("\nEnter element %d: ",i+1);
		scanf("%d",arr+i);
	}

	int r;
	// print_list(head);
	printf("\nEnter the cardinality of subset: ");
	scanf("%d",&r);
	subset_generate(arr,n,r,&head,0,0);
	return 0;
}




/*
Permutation Problem:
Given a set of n distinct elements and an integer r. Write the code to compute all the r permutations of the 
elements of the set l.


Problem 2:
Given a set of values. You are given some denomination of notes. The set will contain denominations of 5 , 10 , 30 etc.
Given an amount to be created. Eg 546. Output number of ways to create 546 from these notes.
Greedy algorithm.
Printf all possible permutations and then output the minimum number required and that particular combination.
Bean packing, subsequence...problem.

*/



// printf("Do you want to enter new value(y or n)?\n");
// 		scanf("%d",&c);
// 		printf("\n");
// 		if(c=='y'){
// 			struct node *element=(struct node *)malloc(sizeof(struct node));
// 			element->next=NULL;

// 			printf("Enter value: \n");
// 			scanf("%d",&(element->val));
// 			insert_sorted(&head,element);
// 		}
// 		else{
// 			break;
// 		}
// 	}

	
// 