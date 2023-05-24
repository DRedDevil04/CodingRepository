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
struct bin_node{
	int key;
	struct bin_node * left;
	struct bin_node * right;
	struct bin_node * parent;
};
typedef struct bin_node tree;
void inorder(tree* t){

	tree* t1=t;
	if(t1==NULL) return;
	inorder(t->left);
	printf("%d ",t->key);
	inorder(t->right);
}
void preorder(tree* t){
	tree* t1=t;
	if(t1==NULL) return;
	printf("%d ",t->key);
	preorder(t->left);
	preorder(t->right);
}
void postorder(tree* t){

	// tree* t1=t;
	if(t==NULL) return;
	postorder(t->left);
	postorder(t->right);
	printf("%d ",t->key);
}
void insertBinTree(tree** t,int val){
	tree * y=NULL;
	tree*x=*t;
	while(x!=NULL){
		y=x;
		if(x->key==val) return;
		else if(x->key<val){
			x=x->right;
		}
		else{
			x=x->left;
		}
	}
	
	tree* t1=(tree*)malloc (sizeof(tree));
	t1->parent =y;
	t1->key=val;
	t1->right=NULL;
	t1->left=NULL;
	if(y==NULL){
		t1->parent =y;
		*t=t1;
		return;
	}
	if(val<y->key){
		y->left=t1;
		return;
	}
	y->right =t1;
	return;
}

tree* searchBinTree(tree * t , int val ){
	if(t==NULL) return t;
	if(t->key==val) return t;
	if(val<t->key){
		return searchBinTree(t->left,val);
	}
	else{
		return searchBinTree(t->right,val);
	}

}
tree* getMinBinTree(tree* t){
	
	while((t)->left!=NULL){
		(t)=(t)->left;
	}
	return t;
}

tree* getMaxBinTree(tree* t){
	
	while((t)->right != NULL){
		(t)=(t)->right;
	}
	return t;
}
// tree * successorBinTree( tree * t){
// 	tree*x=t;
// 	if(t->right !=NULL){
// 		return getMinBinTree(t);
// 	}
// 	tree * y=x->parent;
// 	while(y!=NULL&&y->left!=x){
// 		x=y;
// 		y=y->parent;
// 	}
// 	return y;
// }
// tree * predecessorBinTree( tree * t){
// 	tree*x=t;
// 	if(t->left !=NULL){
// 		return getMaxBinTree(t);
// 	}
// 	tree * y=x->parent;
// 	while(y!=NULL&&y->right!=x){
// 		x=y;
// 		y=y->parent;
// 	}
// 	return y;
// }
void deleteBinTree(tree *temp){

	tree*t=temp;
	// if(t->parent==NULL){
	// 	temp=&((*temp)->right);
	// }
	if(t->right==NULL){
		if(t->parent ->left ==t){
			tree* temp=t;
			t->parent ->left =t->left;
			free(temp);
		}
		else{
			tree* temp=t;
			t->parent ->right  =t->left;
			free(temp);
		}
	}
	if(t->left==NULL){
		if(t->parent ->left ==t){
			tree* temp=t;
			t->parent ->left =t->right;
			free(temp);
		}
		else{
			tree* temp=t;
			t->parent ->right  =t->right;
			free(temp);
		}
	}
	else{
		return;
		// tree* lmax=getMaxBinTree(t->left);
		// lmax->parent=t->parent;
		// if(t->parent ->left ==t){
		// 	tree* temp=t;
		// 	t->parent ->left =t->right;
		// 	free(temp);
		// }
		// else{
		// 	tree* temp=t;
		// 	t->parent ->right  =t->right;
		// 	free(temp);
		// }

	}
}








