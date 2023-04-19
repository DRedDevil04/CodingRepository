
#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
void print_stack(stack **st){
	if((*st)==NULL){
		return;
	}
	int k=(int)pop(&(*st));
	print_stack(st);
	printf("%d ", k);
		
	
}
void PrimeFactors(int N)
{
	
	stack *st;
	create_stack(&st);

	int i = 2;
	while (N != 1) {

		if (N % i == 0) {

			
			push(&st,i);

			while (N % i == 0) {
				N = N / i;
			}
		}

		
		i++;
	}
	print_stack(&st);
}

// Driver Code
int main()
{
	int N;
	printf("Enter n: ");
	scanf("%d",&N);
	printf("\n");
	PrimeFactors(N);
	printf("\n");
	return 0;
}
