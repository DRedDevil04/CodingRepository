#include <stdio.h>
#define MAX 1000
int length(char line[]);
int main(){
	char prev,curr;
	int comment_on=0,comment_type;
	int c,i=0;
	char text[MAX],no_comm[MAX];
	while ((curr=getchar())!=EOF)
	{
		if (curr=='/'){
			continue;
		}
		if(prev=='/' && curr=='*')
		{
			comment_on=1;
			comment_type=0;

		}
		else if (prev=='*' && curr=='/' && comment_type==0)
		{
			comment_on=0;

		}
		else if(prev=='/' && curr=='/')
		{
			comment_on=1;
			comment_type=1;
		}
		else if (curr=='\n' && comment_type==1)
		{
			comment_on=0;
		}
		if (comment_on)
		{
			 no_comm[i]='/';
			 i++;
		}



		if (!(comment_on))
		{
			
				no_comm[i]=curr;
				i++;

			
		}
		prev=curr;

	}
	printf("%s\n",no_comm);


	return 0;
}



