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
	
	printf("\n\n");
	
	printf("In-order is: \n");
	inorder(tree1);
	printf("\n\n");
	printf("Pre-order is: \n");
	preorder(tree1);
	printf("\n\n");
	printf("Post-order is: \n");
	postorder(tree1);



	printf("\nNumber of nodes are : %d", numNodesBinTree(tree1));
	printf("\nSum of values of nodes are : %d", sumNodesBinTree(tree1));
	printf("\nDepth of Binary tree is  : %d", depthBinTree(tree1));

}