#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
	queue *s1,*s2;
	create_queue(&s1,&s2);
	enqueue(&s1,&s2,2);
	enqueue(&s1,&s2,3);
	enqueue(&s1,&s2,4);
	enqueue(&s1,&s2,5);
	printf("\n%d\n",dequeue(&s1,&s2));
	printf("\n%d\n",dequeue(&s1,&s2));
	printf("\n%d\n",dequeue(&s1,&s2));
	printf("\n%d\n",dequeue(&s1,&s2));

	return 0;

}
