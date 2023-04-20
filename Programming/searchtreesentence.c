#include <stdio.h>
#include <useful_funcs.h>
#include <ctype.h>
#define MAXWORD 100
struct node *add_node(char *;struct node *);
struct node *create_node(struct node *)


int main(){
	struct node{
		char *word;
		int count;
		struct node *left_child,*right_child;
	} *root=NULL;

	char word[MAXWORD];
	while((getword(word,MAXWORD))!=EOF){
		if (isalpha(word[0])){
			
		}
	}


}


struct node *add_node(char *word;struct node *place){

	if (place==NULL){
		place=create_node(word);
	}
	else if (strcmp(word,place->word)<0){
		place=add_node(word,place->left_child);
	}
	else if (strcmp(word,place->word)==0){
		(place->count)++;
	}
	else if (strcmp(word,place->word)>0){
		place=add_node(word,place->right_child)
	}
return place;
}

struct node *create_node(struct node p)



