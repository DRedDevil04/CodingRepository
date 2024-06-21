/*
code for aa at end DFA
Assignment 1 Program 2
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
		2,0
	}

};
void dfa(int transition_matrix[][1000],char s[10000],int final_states[1000]){
	int curr_state=0;
	printf("Initial state: q%d \n",curr_state);
	for(int i=0;s[i]!='\0';i++){
		curr_state=transition_matrix[curr_state][s[i]-'a'];
		printf("\ncurr state: q%d and input is %c\n| \nV",curr_state,s[i]);

	}
	for(int i=0;i<1000;i++){
		if(final_states[i]==curr_state){
			printf("\nAccepted\n");
			return;
		}
	}
	printf("\nRejected\n");
}
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
		printf("\nString ends with aa\n");

	}
	else{
		printf("\nString doesnt end with aa\n");
	}


	

	return 0;
}