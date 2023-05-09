/* Devam Desai
IIT2022035 LA5 P1*/



#include <stdio.h>
#include <stdlib.h>
enum branch{IT,ITBI,ECE};
struct st{
	int enrollno;
	enum branch br;
	int cgpa;
	char name[100];
};
typedef struct st student;
void swap(student **x, student **y){
	// printf("\n%s and %s\n",(*x)->name,(*y)->name);
	student* tmp = *x;
	// printf("\n%s and %s\n",(tmp)->name,(*y)->name);
	*x = *y;
	*y = tmp;
	// printf("\n%s and %s\n",(*x)->name,(*y)->name);
}
void print_st_data(student *stu){
		printf("\n\nName of student : %s",stu->name);
		
		printf("\nEnrollment number of student : %d",stu->enrollno);
		
		printf("\nBranch of student (0 for IT,1 for ITBI,2 for ECE): %d",stu->br);
		
		printf("\nCGPA of student : %d\n",stu->cgpa);
		

}
void cg_insert_sort(student **list,int size){
	int i,j;
	student *item;
	for (i=size-1; i>-1; i--)
	{
		item = list[i] ;
		for (j=i-1; (j>=0)&& (list[j]->cgpa < item->cgpa); j--){
			list[j+1] = list[j];
			// for(int i=0;i<=size-1;i++){
			// 	print_st_data(list[i]);
			// }
			// printf("________________________________________");
		}

		list[j+1] = item ;
		// for(int i=0;i<=size-1;i++){
		// 		print_st_data(list[i]);
		// 	}
		// 	printf("___________________HEEEEEHEEEE___%d__________________",j);
}


}
void bin_search(student ** arr, int lo, int hi,int ele){
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(arr[mid]->enrollno>ele){
			hi=mid-1;
		}
		else if(arr[mid]->enrollno<ele){
			lo=mid+1;
		}
		else{	
			print_st_data((arr[mid]));
			return;
		}
	}
	if(arr[hi]->enrollno==ele){
		print_st_data((arr[hi]));
		return;
	}
	else if(arr[lo]->enrollno==ele){
		print_st_data((arr[lo]));
		return;
	}
	printf("\nNo Record found\n");
	return;
}
void lin_search(student **arr,int ele,int n){
	for(int i=0;i<n;i++){
		if(arr[i]->enrollno==ele){
			print_st_data(arr[i]);
			return;
		}
	}
	printf("\nSorry! Record not found.\n");
	return ;

}
void bubb_sort(student ** arr,int n){
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-i-1;j++){
			if(arr[j]->enrollno>arr[j+1]->enrollno){
				swap(arr+j,arr+j+1);
				// for(int i=0;i<=n-1;i++){
				// 	print_st_data(arr[i]);
				// }
				// printf("\n_______________%d__________%d_______________\n",i,j);
			}
		}

	}
	
}

int main(){
	
	int n;
	printf("Enter number of students: ");
	scanf("%d",&n);
	student **arr=(student **)malloc(sizeof(student*)*n);
	for(int i=0;i<=n-1;i++){
		student *ele=(student *)malloc(sizeof(student));
		arr[i]=ele;
	}
	for(int i=0;i<n;i++){

		printf("\nEnter name of student %d:",i+1);
		scanf("%s",(arr[i])->name);
		printf("\nEnter enrollment number of student %d:",i+1);
		scanf("%d",&((arr[i])->enrollno));
		printf("\nEnter branch of student %d (0 for IT,1 for ITBI,2 for ECE):",i+1);
		scanf("%d",&((arr[i])->br));
		printf("\nEnter cgpa of student %d:",i+1);
		scanf("%d",&((arr[i])->cgpa));

	}
	int enrollno;
	printf("\nEnter the enrollment number you want to search for: ");
	scanf("%d",&enrollno);
	lin_search(arr,enrollno,n);
	// for(int i=0;i<=n-1;i++){
	// 	print_st_data(arr[i]);
	// }
	printf("\n\n_______________AFTER BUBBLE SORT_______________\n\n");
	bubb_sort(arr,n);
	
	printf("\nEnter the enrollment number you want to binary search for: ");
	scanf("%d",&enrollno);

	bin_search(arr,0,n-1,enrollno);
	// for(int i=0;i<=n-1;i++){
	// 	print_st_data(arr[i]);
	// }
	cg_insert_sort(arr,n);

	printf("\n\n\nSorted records based on cgpa :\n\n\n");
	for(int i=0;i<=n-1;i++){
		print_st_data(arr[i]);
	}
	return 0;
}