/* A header file containing functions which will be used to declare and use Abstract Data Types

				--By Devam Desai--
*/


struct fifo{
	float val;
	struct fifo *next;
};
typedef struct fifo queue;
struct lifo{
	float val;
	struct lifo * next;
};
typedef struct lifo stack;
void create_stack(stack **top){
	*top=NULL;
}
void push(stack **top,float element){
	stack *ptr=(stack *)malloc(sizeof(stack));
	if(ptr==NULL){
		printf("\nStack is full\n");
		exit(-1);
	}
	ptr->val=element;
	ptr->next=*top;
	*top=ptr;

}
float pop(stack** top){
	if(*top==NULL){
		printf("\nStack is empty\n");
		exit(-1);
	}
	stack *p=*top;
	float k=(*top)->val;
	*top=(*top)->next;
	free(p);
	return k;

}
void create_queue(queue **front, queue **rear){
	*front=NULL;
	*rear=NULL;
}

float dequeue(queue **front, queue **rear){
	if(*front==NULL){
		printf("\nQueue empty");
		exit(-1);
	}
	else{
		float k=(*front)->val;
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






