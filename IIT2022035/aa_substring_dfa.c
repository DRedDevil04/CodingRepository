/*
code for aa DFA
Assignment 1 Program 1
Devam Desai IIT2022035
*/



#include <stdio.h>
int transition_mat[3][2]={
	{
		1,0
	},
	{
		2,0
	},
	{
		2,2
	}

};
int main(){
	char s[1000];
	printf("Enter the string: ");
	scanf("%s",s);
	int curr_state=0;
	printf("Initial state: q%d \n",curr_state);


	for(int i=0;s[i]!='\0';i++){

		curr_state=transition_mat[curr_state][s[i]-'a'];
		printf("\ncurr state: q%d and input is %c\n| \nV",curr_state,s[i]);

	}
	if(curr_state==2){
		printf("\nString contains aa\n");

	}
	else{
		printf("\nString doesnt contain aa\n");
	}


	

	return 0;
}