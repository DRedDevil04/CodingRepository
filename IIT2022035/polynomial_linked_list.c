#include <stdio.h>
#include <stdlib.h>
struct node{
	double val;
	struct node *next;
};
typedef struct node coeff ;
struct polynom{
	coeff* head;
	int deg;
};
typedef struct polynom Poly;
void print_poly(coeff *head){
	coeff* ptr=head;
	printf("\nAdded Polynomial is : ");
	int i=0;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		printf("+ (%.2lf)x^%d ",ptr->val,i);
		i++;
	}
	printf("\n");
}
Poly *add(Poly *poly1,Poly *poly2){
	if(poly1->deg<poly2->deg){
		coeff* ptr1=poly1->head;
		coeff* ptr2=poly2->head;
		
		for(;ptr1!=NULL;ptr1=ptr1->next,ptr2=ptr2->next){
			
			ptr2->val+=ptr1->val;
		}
		return poly2;
		
	}
	else {
		coeff* ptr1=poly1->head;
		coeff* ptr2=poly2->head;
		
		for(;ptr2!=NULL;ptr1=ptr1->next,ptr2=ptr2->next){
			
			ptr1->val+=ptr2->val;
		}
		return poly1;
	}
	// else{
	// 	coeff* ptr1=poly1->head;
	// 	coeff* ptr2=poly2->head;
		
	// 	for(;ptr2!=NULL;ptr1=ptr1->next,ptr2=ptr2->next){
			
	// 		ptr1->val+=ptr2->val;
	// 	}
	// 	return poly1;
	// }
}
void poly_input(Poly *poly){
	coeff* prev;
	if(poly->deg==0){
		return;
	}
	for(int i=0;i<=poly->deg;i++){
		coeff *term=(coeff*)malloc(sizeof(coeff));
		if(i==0){
			poly->head=term;
			printf("\nEnter coefficient of term x^%d: ",i);
			scanf("%lf",&(term->val));
			term->next=NULL;
			prev=term;
			continue;
		}

		printf("\nEnter coefficient of term x^%d: ",i);
		scanf("%lf",&(term->val));
		prev->next=term;
		term->next=NULL;
		prev=term;


	}
}

int main(){
	Poly *poly1=(Poly*)malloc(sizeof(Poly)),*poly2=(Poly*)malloc(sizeof(Poly));
	printf("\nEnter degree of first polynomial: ");
	scanf("%d",&(poly1->deg));

	poly_input(poly1);
	printf("\nEnter degree of second polynomial: ");
	scanf("%d",&(poly2->deg));

	poly_input(poly2);

	Poly * added=add(poly1,poly2);
	print_poly(added->head);



	return 0;
}