#include <stdio.h>
void str_check();
int main()
{str_check();
	/* code 
	char *hi=str_check();
	printf("%s\n",hi);
	return 0;
	*/
}
void str_check(){
	char stru[100],*p,c,i=0;
	p=stru;
	
	while((c=getchar())!=EOF){

		stru[i++]=c;
		
	}
	
	printf("%s\n",p );

}