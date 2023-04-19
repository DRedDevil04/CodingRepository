#include <stdio.h>
#include <stdlib.h>
// #include "adt.h"


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
		return '-';
	}
	stack *p=*top;
	char k=(*top)->val;
	*top=(*top)->next;
	free(p);
	return k;

}



int main(){
	char paren[50];
	char open[]={'(','{','['};
	char close[]={')','}',']'};
	printf("\nEnter your parenthesis string: ");
	scanf("%s",paren);
	stack *parens;
	int flag=0;
	create_stack(&parens);
	for(int i=0;paren[i]!='\0';i++){
		if(paren[i]=='('||paren[i]=='{'||paren[i]=='['){
			push(&parens,paren[i]);
		}
		else{
			char c=pop(&parens);
			if(c=='-'){
				flag=1;
				break;
			}
			if(paren[i]==')') c--;
			
			if(c==paren[i]-2){

				continue;
			}
			else{
				flag=1;
				break;
			}
		}
	}
	if(flag==0 && parens==NULL){
		printf("\nVALID\n");
	}
	else{
		printf("\nINVALID\n");
	}

	return 0;

}
