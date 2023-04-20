/*#include <stdio.h>
void str_check();
int main()
{str_check();
	code 
	char *hi=str_check();
	printf("%s\n",hi);
	return 0;
	
}
void str_check(){
	char stru[100],*p,c,i=0;
	p=stru;
	
	while((c=getchar())!=EOF){

		stru[i++]=c;
		
	}
	
	printf("%s\n",p);

}
*/
#include <iostream>
#include <string>
using namespace std;
void runCase(),runCase2();
bool checkCase(int m,int arr[]);
int main() {
	// your code goes here
	int test_case,n,k;
	cin>>test_case;
	for(int i=1;i<=test_case;i++){
	    runCase2();
	}
	
	return 0;
}

void runCase2(){
	int n,k;
    string bin,sin;
    
    sin=bin;
    cin>>n>>k;
    cin>>bin;
    for (int j=1;j<=k+1;j++){
    	for(int i=0;i<=n-1;i++){
    		if (sin[i]=='0'){
    			if (i>0){
                if (sin[i-1]=='1'){
                    bin[i]='1';
                }
        }
        if (i<n-1 ){
            if (sin[i+1]=='1'){
                bin[i]='1';
            }
            }  
    		}
    	if (sin[i]=='1'){
    			bin[i]='0';

    	}
    
    



    }
    sin=bin;

}
cout<<"\n"<<bin<<"\n";
}
