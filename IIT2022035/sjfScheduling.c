// SJF Scheduling

#include<stdio.h>

#include<limits.h>

 

/*Declaring heap globally so that we do not need to pass it as an argument every time*/

/* Heap implemented  here is Min Heap */

 
struct program {
		int BT;
		int AT;
};
struct program heap[1000000];
int  heapSize;

/*Initialize Heap*/

void Init() {

    heapSize = 0;

    heap[0].BT = -INT_MAX;

}

 

/*Insert an element into the heap */

void Insert(struct program element) {

    heapSize++;

    heap[heapSize].AT= element.AT; 
    heap[heapSize].BT = element.BT;/*Insert in the last place*/

    /*Adjust its position*/

    int now = heapSize;

    while (heap[now / 2].BT > element.BT) {
    	printf("bjhsdbhjbhjds");
        heap[now].BT = heap[now / 2].BT;
        heap[now].AT = heap[now / 2].AT;


        now /= 2;

    }

    heap[now].BT = element.BT;
    heap[now].AT = element.AT;

}

 

struct program DeleteMin() {

    /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased.

     Now heap[1] has to be filled. We put the last element in its place and see if it fits.

     If it does not fit, take minimum element among both its children and replaces parent with it.

     Again See if the last element fits in that place.*/

    int  child, now;
    struct program minElement, lastElement;
    minElement = heap[1];

    lastElement = heap[heapSize--];

    /* now refers to the index at which we are now */

    for (now = 1; now * 2 <= heapSize; now = child) {

        /* child is the index of the element which is minimum among both the children */

        /* Indexes of children are i*2 and i*2 + 1*/

        child = now * 2;

        /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one

         child */

        if (child != heapSize && heap[child + 1].BT < heap[child].BT) {

            child++;

        }

        /* To check if the last element fits ot not it suffices to check if the last element

         is less than the minimum element among both the children*/

        if (lastElement.BT > heap[child].BT) {

            heap[now].BT = heap[child].BT	;
            heap[now].AT = heap[child].AT	;


        } else /* It fits there */

        {

            break;

        }

    }

    heap[now].BT = lastElement.BT;
    heap[now].AT = lastElement.AT;


    return minElement;

}

 

int main() {

    int number_of_elements;

    printf("SJF Scheduling :\nEnter number of programs: ");

    scanf("%d", &number_of_elements);

    int iter;
    struct program element;

    Init();

    printf("Enter the burst time and arrival time : ");

    for (iter = 0; iter < number_of_elements; iter++) {

        scanf("%d%d", &(element.BT),&(element.AT));

        Insert(element);

    }

    for (iter = 0; iter < number_of_elements; iter++) {
    	struct program temp=DeleteMin();
        printf("\n%d %d",temp.BT,temp.AT );

    }

    printf("\n");

    return 0;

}