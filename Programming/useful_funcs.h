#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char INPUT_BUFF[10];
int BUFF_COUNT=0;
char BUFF_CHAR;
char getch();
void ungetch();
int getword(char *,int);
char getch(){
	char c=(BUFF_COUNT>0)?INPUT_BUFF[--BUFF_COUNT]:(BUFF_CHAR=getchar());
	return c;
}

void ungetch(){
	INPUT_BUFF[BUFF_COUNT++]=BUFF_CHAR;
}
int getword(char *word,int lim){
	char *w=word;
	while((char c=getch())==' '){
		;
	}
	if (c!=EOF){
		*w++=c;
	}
	if (!isalpha(c)){
		*w='\0';
		return c;
	}
	for(;--lim>0;w++){
		if (!isalnum(*w=getch())){
			ungetch();
			w--;
			break;


		}
	}
	*w='\0';
	return word[0];
}