/*Devam Desai 
IIT2022035 Assignment 2 P1*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
	float x;
	float y;
};
struct point mid_point(struct point p1,struct point p2){
	p1.x=(p1.x+p2.x)/2;
	p1.y=(p1.y+p2.y)/2;
	return p1;
}
double distance(struct point p1,struct point p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
int main(){
	struct point p1,p2;
	printf("Enter first coordinate(x y):\n");
	scanf("%f%f",&p1.x,&p1.y);
	printf("\nEnter second coordinate(x y):\n");
	scanf("%f%f",&p2.x,&p2.y);
	printf("\nThe distance is: %.3lf",distance(p1,p2));
	printf("\nThe x coordinate of midpoint is : %.2lf\nThe y coordinate of midpoint is %.2lf\n",mid_point(p1,p2).x,mid_point(p1,p2).y);
	return 0;
}