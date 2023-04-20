#include <stdio.h>
#include <ctype.h>
#include <string.h>
char INPUT_BUFF[10];
int BUFF_COUNT=0;
char BUFF_CHAR;
int arr_size,arr_check=0,run_time=0;

char *dir_dcl();
void dcl();
char getch();
void ungetch();

int main(){
	char out[1000];
	out=dir_dcl();

	printf("%s\n",dir_dcl);
	return 0;
}


int dir_dcl(){
	char out_block[100];
	strcpy(out_block,' ');
	char c;
	while((c=getch())!=EOF){

		switch (c){
			case '(':
				dcl();
				strcat(out_block,dir_dcl());
				break;
			case '[':
				dcl();
				scanf("%d",&arr_size);
				arr_check=1;
				break;
			case '*':
				dcl();
				strcat(out_block,"pointer to");
				break;
			case ')':
				if (run_time>0){
					strcat(out_block," function");
					return out_block;
				}
				return out_block;
			case ';':
				return 0;



			default:
				break;
		}
	


	}

	return out_block;
}


char getch(){
	char c=(BUFF_COUNT>0)?INPUT_BUFF[--BUFF_COUNT]:(BUFF_CHAR=getchar());
	return c;
}

void ungetch(){
	INPUT_BUFF[BUFF_COUNT++]=BUFF_CHAR;
}

void dcl(){
	char c;
	
	while(isalpha(c=getch())){
		run_time=1;
	}
	ungetch();
}


