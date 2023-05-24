#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
int main(){
	tree * tree1=NULL;
	printf("\nEnter first value: \n");
	int val;
	scanf("%d",&val);
	insertBinTree(&tree1,val);
	for(int i=0;;i++){
		char c;
		printf("Do you want to enter new value(y or n)?\n");
		scanf(" %c",&c);
		printf("\n");
		if(c=='y'){
			
			printf("Enter value: \n");
			scanf("%d",&val);
			insertBinTree(&tree1,val);
		}
		else{
			break;
		}
	}
	// printf("%d",tree1->left->key);
	// int k;
	// printf("\nEnter number to find successor for :");
	// scanf("%d",&k);
	printf("\n\n");
	// printf("\nMIN is :%d\n",(*(getMinBinTree(&tree1)))->key);
	// printf("\nMAX is :%d\n",(*(getMaxBinTree(&tree1))->key));

	// printf("\nSuccessor of %d is :%d\n",k,(successorBinTree(searchBinTree(tree1,k))->key));
	printf("In-order is: \n");
	inorder(tree1);
	printf("\n\n");
	printf("Pre-order is: \n");
	preorder(tree1);
	printf("\n\n");
	printf("Post-order is: \n");
	postorder(tree1);
	printf("\n\n\n___________________After Deletion_________________\n\n\n");
	if(tree1->left==NULL && tree1->right ==NULL){

	 printf("\nNO ELEMENT\n");
	 exit(-1);
	}
	if(tree1->left==NULL){
		printf("In-order is: \n");
		inorder(tree1->right);
		printf("\n\n");
		printf("Pre-order is: \n");
		preorder(tree1->right);
		printf("\n\n");
		printf("Post-order is: \n");
		// printf("\n%p\n",tree1->right);
		postorder(tree1->right);
		return 0;
	}
	deleteBinTree((getMinBinTree(tree1)));
	printf("In-order is: \n");
	
	inorder(tree1);
	printf("\n\n");
	printf("Pre-order is: \n");
	preorder(tree1);
	printf("\n\n");
	printf("Post-order is: \n");
	postorder(tree1);
	return 0;
}