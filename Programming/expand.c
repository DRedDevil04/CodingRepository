#include <stdio.h>
void expand(char str[]);
void add(char str[],int n);
int main(){
char word[10]="A-";
expand(word);
printf("%s",word);
return 0;
}
void expand(char str[500]){
	int i=0,count;
	char curr,last;

	while(str[i]!='\0'){
		curr=str[i];
		if (curr=='-'){
			if (last>=65 && last<=90){
				for(int n=1;n<=90-last;n++){
					add(str,i);
					for(int k=i;k<=i+90-last;k++){
						count=90-last;
						char ch=count;
						str[k]=ch;
					}
				}

			}
		}
		i++;
		last=curr;
	}



}

void add(char str[500], int i){
	for (int j=499;j>=i;j--){
					str[j+1]=str[j];


				}


}