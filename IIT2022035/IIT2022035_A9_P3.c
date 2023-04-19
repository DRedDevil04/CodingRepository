/*Devam Desai
IIT2022035 Assignment 9 Program 3*/


#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrixInput(int mat[][COLS]){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			int *point = &mat[0][0];
			printf("Enter element of matrix \n");
			scanf("%d", point+(i*COLS)+j);
		}
	}
}
void matrixPrint(int mat[][COLS]){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			int *point = &mat[0][0];
			printf("%d ", *(point + (i*COLS)+j));
		}
		printf("\n");
	}
	printf("\n\n");
}
void matrixAdd(int mat1[][COLS],int mat2[][COLS],int res[][COLS]){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			*(*(res+i)+j) = *(*(mat1+ i) + j) + *(*(mat2+i)+j);
		}
	}
}
int main(){
	int A[ROWS][COLS],B[ROWS][COLS],C[ROWS][COLS];
	
	matrixInput(A);
	printf("Enter elements of 2nd matrix: \n");
	matrixInput(B);
	
	matrixPrint(A);
	matrixPrint(B);
	
	matrixAdd(A,B,C);
	
	printf("The sum is \n");
	matrixPrint(C);
}
	
	
	
	
	
	
