#include <stdio.h>
#define MAX 100
int getLine(char line[]);
void reverse(char line[]);
int length(char line[]);

main(){
  char lines[MAX];
  int length;
  while((length=getLine(lines))>0){

    reverse(lines);
    printf("%s",lines);
  }
}
int getLine(char s[MAX]){
  char c;
  int i=0;
  while ( (c = getchar()) != EOF && c != '\n'){
    s[i]=c;
    ++i;
  }
  if (s[i]=='\n'){
    i++;
  }
    s[i]='\0';

    return i;
  }

  


int length(char line[MAX]){
  int i=0;
  while (line[i]!='\0'){
    i++;
  }
return i;
}
void reverse(char line[])
{
  int i_front = 0;
  int i_back = length(line);
  char temp;

  i_back -= 2;
  while (i_back > i_front)
  {
    temp = line[i_front];
    line[i_front] = line[i_back];
    line[i_back] = temp;

    ++i_front;
    --i_back;
  }
}

