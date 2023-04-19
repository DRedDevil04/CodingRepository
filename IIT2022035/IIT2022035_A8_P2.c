/*Devam Desai
IIT2022035	Assignment 8 Program 2*/

#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;

};
float distance(struct point,struct point);
int main(){
	struct point Points[5];
	for(int i=0;i<5;i++){
		
		printf("\nEnter point %d(x,y): ",i+1);
		scanf("%d%d",&Points[i].x,&Points[i].y);

	}
	float min=100000000;
	int p1,p2;
	for(int j=0;j<5;j++){
		for(int k=0;k<5;k++){
			if(j==k){
				continue;
			}
			else{
				float s=distance(Points[j],Points[k]);
				if(min>s){
					min=s;
					p1=j;
					p2=k;
					

				}
				else{
					continue;
				}
			}
		}
	}
	printf("\nClosest distance is between point %d and point %d",p1+1,p2+1);

	
}
float distance(struct point p1,struct point p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
