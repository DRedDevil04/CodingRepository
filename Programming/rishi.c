#include <stdio.h>
#include <stdlib.h>
int main(void) {
// your code goes here
	int *ip=(int*) malloc(20);
	int s[5];
	for(int i=0;i<5;i++){
		scanf("%d %d",ip++,s[i]);
	}
	for(int i=0;i<5;i++){
		printf("%d %d\n",(*ip)++,s[i]);
	}
	return 0;
}
