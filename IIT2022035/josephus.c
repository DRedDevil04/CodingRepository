#include <stdio.h>
#include <stdlib.h>
struct student{

	int num;
	struct student * next;
};
void print_list(struct student *head){
	/*
	prints the list given its head node
	*/
	for(struct student *ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("\nElement is %d",ptr->num);
	}
}
typedef struct student person;
 
int Josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        /* The position returned by josephus(n - 1, k) is
           adjusted because the recursive call josephus(n -
           1, k) considers the original position
           k%n + 1 as position 1 */
        return (Josephus(n - 1, k) + k - 1) % n + 1;
}
int josephus(n,k){
	person *head=(person *)malloc(sizeof(person));
	person* last=head;
	head->num=n;
	head->next=NULL;

	for(int i=n-1;i>=1;i--){
		person *p=(person *)malloc(sizeof(person));
		p->num=i;
		p->next=head;
		head=p;
	}
	print_list(head);
	
	last->next=head;
	person * p=head;
	person * prev=head;
	int count =k-1;
	int size=n;
	while(1){
		if(count==0){
			prev->next=p->next;
			size--;

			free(p);
			p=prev->next;
			count=k-1;
		}
		if(size==1){
			break;
		}
		count --;
		prev=p;
		p=p->next;
	}

	return p->num;
}
int main(){
	int n,k;
	printf("Enter n and k: ");
	scanf("%d %d",&n,&k);
	printf("\nThe safe place is : %d and %d",josephus(n,k),Josephus(n,k));
}
