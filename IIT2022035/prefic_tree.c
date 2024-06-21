#include <stdio.h>
#include <stdlib.h>
// #include "adt.h"
struct bin_node{
	char key;
	struct bin_node * left;
	struct bin_node * right;
	struct bin_node * parent;
};
typedef struct bin_node tree;
void inorder(tree* t){

	tree* t1=t;
	if(t1==NULL) return;
	inorder(t->left);
	printf("%c ",t->key);
	inorder(t->right);
}
void preorder(tree* t){
	tree* t1=t;
	if(t1==NULL) return;
	printf("%c ",t->key);
	preorder(t->left);
	preorder(t->right);
}
void postorder(tree* t){

	// tree* t1=t;
	if(t==NULL) return;
	postorder(t->left);
	postorder(t->right);
	printf("%c ",t->key);
}

int main(){
	tree * tree1=NULL;
	tree* temp=NULL,*tempNum =NULL;
	char str [100];
	printf("Enter the prefix sorting : ");
	scanf("%s",str);
	printf("\n%s\n",str);
	int i=0;
	while(str[i]!='\0'){
		
		if(str[i]=='-' || str[i]=='+' || str[i]=='*' || str[i]=='/'){
			
			tree * t=(tree*)malloc(sizeof(tree));
			if (tree1==NULL){
				tree1=t;
				t->key=str[i];
				t->right =NULL;
				t->left =NULL;
				t->parent=NULL;
				temp =tree1;
				tempNum=tree1;
			}
			else{

				temp->right =t;
				t->key=str[i];
				t->right =NULL;
				t->left =NULL;

				temp=temp ->right;
				if(tempNum==NULL){
					tempNum=t;
				}
			}
			
		}
		else{
			tree * t=(tree*)malloc(sizeof(tree));
			
			if(tempNum==NULL){

				// tempNum=t;
				t->key=str[i];
				t->left=NULL;
				t->right=NULL;
				temp->right=t;
				
			}

			else{
				t->key=str[i];
				t->left=NULL;
				t->right=NULL;
				tempNum->left=t;

				tempNum=tempNum->right;
			}
			
			
		}
		i++;
	}
	
	printf("Pre-order is: \n");
	preorder(tree1);
	printf("\n\n");
	printf("Post-order is: \n");
	postorder(tree1);
	printf("\n\n");
	printf("In-order is: \n");
	inorder(tree1);
	


	return 0;
}