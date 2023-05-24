#include <stdio.h>
#include <stdlib.h>
struct node {
	int val;
	struct node * next;

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
void bubb(int arr[], int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if (arr[j+1] < arr[j]) swap(&arr[j], &arr[j+1]);
            // printf("%\n",j);
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
struct node *vector=NULL;
void solve(int num,int denoms[],int n,int sum){
	if(sum==n){
		printf("\nOne way is: ");
		print_list(vector);
		printf("\n");
		return;
	}
	if(sum>n){
		return;
	}
	for(int i=0;i<num;i++){
		struct node *ele=(struct node *)malloc(sizeof(struct node));
		ele->val=denoms[i];
		insert(&vector,ele);
		solve(num,denoms,n,sum+denoms[i]);
		delete_tail(&vector);
	}
}
void greedy(int num,int denoms[],int k,int n){
	if(k==-1){
		return;
	}
	if(n==0){
		print_list(vector);
		return;
	}
	if(n<0){

		return;
	}

	
	if(n>=denoms[k]){
		struct node *ele=(struct node *)malloc(sizeof(struct node));
		ele->val=denoms[k];
		insert(&vector,ele);
		greedy(num,denoms,k,n-denoms[k]);

	}
	else{

		struct node *ele=(struct node *)malloc(sizeof(struct node));
		int i=k;
		while(denoms[i]>n && i>=0){
			i--;
		}
		if(i==-1){
			return;
		}
		ele->val=denoms[i];
		insert(&vector,ele);
		greedy(num,denoms,i,n-denoms[i]);
	}
	
	delete_tail(&vector);

}
struct node * least_=NULL;
void dp_coin(nums,denoms,number){
	
	return;
}
int main(){
	int num;
	printf("Enter number of denominations: ");
	scanf("%d",&num);
	int *denoms=(int *)malloc(sizeof(int)*num);
	for(int i=0;i<num;i++){
		printf("\nEnter the denomination: ");
		scanf("%d",denoms+i);
	}
	bubb(denoms,num);
	printf("\nEnter the number you want to check: ");
	int number;
	scanf("%d",&number);
	solve(num,denoms,number,0);
	printf("\n\n\n\n\n\n\nThe Best way is :");

	greedy(num,denoms,num-1,number);
}
