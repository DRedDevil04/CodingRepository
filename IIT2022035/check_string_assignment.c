#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fifo{
	char val;
	struct fifo *next;
};
typedef struct fifo queue;
struct lifo{
	char val;
	struct lifo * next;
};
typedef struct lifo stack;

void create_stack(stack **top){
	*top=NULL;
}
void push(stack **top,char element){
	stack *ptr=(stack *)malloc(sizeof(stack));
	if(ptr==NULL){
		printf("\nStack is full\n");
		exit(-1);
	}
	ptr->val=element;
	ptr->next=*top;
	*top=ptr;

}
char pop(stack** top){
	if(*top==NULL){
		printf("\nStack is empty\n");
		exit(-1);
	}
	stack *p=*top;
	char k=(*top)->val;
	*top=(*top)->next;
	free(p);
	return k;

}

void create_queue(queue **front, queue **rear){
	*front=NULL;
	*rear=NULL;
}

char dequeue(queue **front, queue **rear){
	if(*front==NULL){
		printf("\nQueue empty");
		exit(-1);
	}
	else{
		char k=(*front)->val;
		queue* ptr=*front;
		*front=(*front)->next;
		free(ptr);
		return k;

	}
}
void enqueue(queue **front,queue **rear,float element){
	queue* ptr=(queue*)malloc(sizeof(queue));
	if(*rear==NULL){
		*front = ptr;
		*rear=ptr;
		ptr->val=element;
		ptr->next=NULL;
	}
	else{
		(*rear)->next=ptr;
		ptr->next=NULL;
		*rear=ptr;
		ptr->val=element;

	}
}
void wxw(char s[]){

	queue *q,*qr;
	create_queue(&q,&qr);
	int n=strlen(s);
	
	for(int i=0;i<n/2;i++){
		enqueue(&q,&qr,s[i]);	
	}
	int i=n/2;
	if(n%2==1){
	
		i++;
	}
	for(;i<n;i++){
		char c;
		while(q!=NULL && s[i]!=(c=dequeue(&q,&qr))){
			// printf("\n%c and %c",c,s[i]);
			i++;
			continue;
		
		
		}
		break;
	
	}
	
	
	if(q==NULL){
	
		printf("\nNO\n");
	
	}
	else{
		printf("\nYES\n");
	
	}
	return;
}

void ww(char s[]){
	queue *q1,*q1_r;
	create_queue(&q1,&q1_r);
	int n=strlen(s);
	if(n%2==1){
		printf("\nNO\n");
		return;
	}
	for(int i=0;i<(n/2);i++){
	
		enqueue(&q1,&q1_r,s[i]);
	
	}
	int flag=0;
	for(int i=n/2;i<n;i++){
	
		if(s[i]!=dequeue(&q1,&q1_r)){
			
			flag=1;
			break;
		}
	
	}
	if(flag==0){
		printf("\nYES\n");
	}
	else{
		printf("\nNO\n");
	}
	return;
		
}

void wwr(char s[]){
	if(s[0]==s[strlen(s)-1]){
		printf("\nYES\n");
	}
	else{
		printf("\nNO\n");
	}
	return;
}




int main(){


	
	char s[100];
	printf("Enter string : ");
	scanf("%s",s);
	int n=strlen(s);
	int type;
	printf("\nEnter the type of check( 1 for w#w, 2 for ww, 3 for w#wr ):");
	scanf("%d",&type);
	if(type==1){
		wxw(s);
	}
	
	else if(type==2){
	
		ww(s);
	}
	else if(type==3){
	
		wwr(s);
	
	}
	else{

		printf("\nNo such option\n");
	}
	

	return 0;
}

