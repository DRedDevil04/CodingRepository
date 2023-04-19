/*Devam Desai
IIT2022035	Assingment 8 Program 1*/




#include <stdio.h>
int main(){
	struct Marks{
		int phy_marks;
		int chem_marks;
		int math_marks;
	} students[6];
	int x=5;

	while(x--){

		printf("\nEnter marks of student %d(P C M):",5-x);
		scanf("%d%d%d",&students[x].phy_marks,&students[x].chem_marks,&students[x].math_marks);
		printf("\nOverall Percentage is : %d%%",(students[x].phy_marks+students[x].chem_marks+students[x].math_marks)/3);
	}
	return 0;
}