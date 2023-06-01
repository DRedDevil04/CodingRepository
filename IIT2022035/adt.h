/* A header file containing functions which will be used to declare and use Abstract Data Types

				--By Devam Desai--
*/
#define COUNT 10
int max(int a , int b){
	if(a>b) return a;
	else return b;
}
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
	int height;
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
int numNodesBinTree(tree* t){
	if(t==NULL){
		return 0;
	}
	return (numNodesBinTree(t->left)+numNodesBinTree(t->right))+1;
}
int sumNodesBinTree(tree* t){
	if(t==NULL){
		return 0;
	}
	return (sumNodesBinTree(t->left)+sumNodesBinTree(t->right))+t->key;
}
int depthBinTree(tree* t){
	if(t==NULL){
		return 0;
	}
	int l=(depthBinTree(t->left)),h=(depthBinTree(t->right));
	if(l>h){
		return l+1;

	}
	else{
		return h+1;
	}
	
}
void LCRSconv(tree* t){
	if(t==NULL){
		// printf("dsjkk\n");
		return;
	}
	else{
		tree* temp=t->right;
		LCRSconv(t->left);
		LCRSconv(temp);
		if(t->parent==NULL){
			// printf("%d   k\n",t->key);
			return;
		}
		
		// LCRSconv(t->right);
		
		if(t==t->parent->left){
			
			if(t->left==NULL && t->right!=NULL){
				t->left=t->right ;
				t->right =NULL;
				LCRSconv(t->left);
				return;
			}
			t->right=t->parent->right;
			
			t->parent->right=NULL;
		}
		else{
			t->right=NULL;
			// t->left=NULL;
		}
		
		
	}
}
void traverseLCRS(tree *t){
	if(t==NULL){
		return;
	}

	traverseLCRS(t->left);
	// traverseLCRS(t->right);
	printf("%d ",t->key);
	traverseLCRS(t->right);
}

void getHeight(tree* t){
	int lh=0,rh=0;
		if((t)->left!=NULL){
			lh+=(t)->left->height;
		}
		if((t)->right!=NULL){
			rh+=(t)->right->height;
		}
		(t)->height=max(lh+1,rh+1);
}
void leftRotate(tree * t){
	if(t->right==NULL){
		return;
	}
	tree* temp = t->right;
	if(t->parent->right ==t){
		t->parent->right=temp;
		temp->parent=t->parent;
		t->parent=temp;	
		t->right=temp->left;
		temp->left=t;
		if(t->right!=NULL) t->right->parent=t;
	}
	else{	
		t->parent->left=temp;
		temp->parent=t->parent;
		t->parent=temp;	
		t->right=temp->left;
		temp->left=t;
		if(t->right!=NULL) t->right->parent=t;
		
		
	}
	if(temp->left!=NULL)getHeight(temp->left);
	if(temp->right!=NULL) getHeight(temp->right);
	if(temp!=NULL)getHeight(temp);
}
void leftRotateRoot(tree** t){
	if((*t)->right==NULL){
		return;
	}
	tree* temp= * t;
	(*t)=(*t)->right;
	// printf("kjnsdcnjnddndsnjkcdsjkscdnj\n\n");
	tree * temp2=(*t)->left;
	(*t)->left=temp;
	temp->right=temp2;
	if(temp2!=NULL){
		temp2->parent=temp;
	}
	(*t)->parent=NULL;
	(temp->parent)=(*t);
	// printf("%p %d\n",(*t)->left->key,(*t)->right->left ->key);
	if((*t)->right!=NULL)getHeight((*t)->right);
	if((*t)->left!=NULL)getHeight((*t)->left);
	if((*t)!=NULL)getHeight(*t);

	// (*t)->left
}
void rightRotateRoot(tree** t){
	tree* temp= * t;
	(*t)=(*t)->left;
	// printf("kjnsdcnjnddndsnjkcdsjkscdnj\n\n");
	tree * temp2=(*t)->right;
	(*t)->right=temp;
	temp->left=temp2;
	if(temp2!=NULL){
		temp2->parent=temp;
	}
	(*t)->parent=NULL;
	(temp->parent)=(*t);
	// printf("%p %d\n",(*t)->right->key,(*t)->left->right ->key);
	
	
	if((*t)->right!=NULL)getHeight((*t)->right);
	if((*t)->left!=NULL)getHeight((*t)->left);
	if((*t)!=NULL)getHeight(*t);

	// (*t)->right
}



// void rightRotate(tree * t){
	
// 	if(t->parent->left ==t){
// 		tree* temp = t->left;
// 		t->parent ->left =t->left;
// 		t->left=temp->right;
// 		if(temp->right!=NULL) temp->right->parent=t;
// 		temp->right=t;
// 		temp->parent=t->parent;
// 		t->parent =temp;
// 		// (t->left)->height=max(abs((t)->left->left->height),abs(((t)->->left->right->height))+1);
// 		int lh=0,rh=0;
// 		if(temp->right->right==NULL && temp->right->left==NULL){
// 		temp->right->height=1;
// 	}
// 		getHeight(temp);


// 	}
// 	else{
// 		tree* temp = t->left;
// 		t->parent ->right =t->left;
// 		t->left=temp->right;
// 		temp->right->parent=t;
// 		temp->right=t;
// 		temp->parent=t->parent;
// 		t->parent =temp;
// 		if(temp->right->right==NULL && temp->right->left==NULL){
// 		temp->right->height=1;
// 		}
// 		getHeight(temp);
// 	}
// }
void rightRotate(tree * t){
	if(t->left==NULL){
		return;
	}
	tree* temp = t->left;
	if(t->parent->right ==t){
		t->parent->right=temp;
		temp->parent=t->parent;
		t->parent=temp;	
		t->left=temp->right;
		temp->right=t;
		if(t->right!=NULL) t->right->parent=t;
		if(t->left!=NULL) t->left->parent=t;
	}
	else{	
		t->parent->left=temp;
		temp->parent=t->parent;
		t->parent=temp;	
		t->right=temp->left;
		temp->left=t;
		if(t->right!=NULL) t->right->parent=t;
		if(t->left!=NULL) t->left->parent=t;
		
	}
	if(temp->right!=NULL)getHeight(temp->right);
	if(temp->left!=NULL) getHeight(temp->left);
	if(temp!=NULL)getHeight(temp);
}
void insertAVL(tree** t, int val){
	if((*t)->key > val){
		if((*t)->left !=NULL){
			insertAVL(&((*t)->left),val);
			(*t)->height=max(abs((*t)->height),(abs((*t)->left->height))+1);
		}
		else{
			tree* t1=(tree *)malloc(sizeof(tree));
			t1->key=val;
			t1->left = NULL;
			t1->right=NULL;
			t1->height=1;
			t1->parent = *t;
			(*t)->left = t1;
			(*t)->height=max(abs((*t)->height),abs(((*t)->left->height))+1);
		}
	}
	else if((*t)->key <val){
		if((*t)->right !=NULL){
			insertAVL(&((*t)->right),val);
			(*t)->height=max(abs((*t)->height),(abs((*t)->right->height))+1);
		}
		else{
			tree* t1=(tree *)malloc(sizeof(tree));
			t1->key=val;
			t1->left = NULL;
			t1->right=NULL;
			t1->height=1;
			t1->parent = *t;
			(*t)->right = t1;
			(*t)->height=max(abs((*t)->height),(abs((*t)->right->height))+1);
		}
	}
	else{
		return;
	}
	int lh=0,rh=0;
	if((*t)->left!=NULL){
		lh+=(*t)->left->height;
	}
	if((*t)->right!=NULL){
		rh+=(*t)->right->height;
	}
	int bal = abs(lh)-abs(rh);
	// printf("bal is:  %d. for %d and lh is %d and rh is %d\n",bal,(*t)->key,lh,rh);
	tree* p=*t;
	if(bal>1){
		int flag=0;
		if(p->right != NULL){
		if(val>p->left->key){
			if((*t)->parent==NULL){
			leftRotateRoot(&(p->left));
			flag=1;
		}
		if(!flag) leftRotate(p->left);
		if((*t)->parent==NULL){
			
			rightRotateRoot(t);
			return;
		}
		rightRotate(*t);
		return;
		}
	}
		// printf("rightRotating for  %d\n",(*t)->key);
		if((*t)->parent==NULL){
			
			rightRotateRoot(t);
			return;
		}
		rightRotate(*t);
	}	
	if(bal<-1){
		// printf("leftRotating for  %d\n",(*t)->key);	
		int flag=0;
		if(p->right != NULL){


		if(val<p->right->key){
			if((*t)->parent==NULL){
			rightRotateRoot(&(p->right));
			flag=1;
		}
		if(!flag) rightRotate(p->right);
		if((*t)->parent==NULL){
			// printf("\nright for C3\n");
			leftRotateRoot(t);
			return;
		}
		leftRotate(*t);
		return;
		}
	}
		// printf("leftRotating for  %d\n",(*t)->key);	
		if((*t)->parent==NULL){
			leftRotateRoot(t);
			return;
		}
		leftRotate(*t);
	}
}
void print2DUtil(tree* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d \n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(tree* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

