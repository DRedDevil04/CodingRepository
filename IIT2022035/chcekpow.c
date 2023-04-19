
#include<stdio.h>
void pow(float,int);
int main(){
	pow(3,-2);
	return 0;
}




void pow(float x,int y){
	float val=1.0;

	if(y<0){
		
		while(y++){
			val=val/x;
		}
		
	}
	else{
		
		while(y--){
		val*=x;
	}
	

}
printf("\nValue is %.3f",val);
}
