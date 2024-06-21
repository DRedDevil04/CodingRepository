// SJF Scheduling

#include<stdio.h>

#include<limits.h>
#include <stdlib.h>
 

/*Declaring heap globally so that we do not need to pass it as an argument every time*/

/* Heap implemented  here is Min Heap */

 
struct program {
		int BT;
		int AT;
        int num;
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
    	
        heap[now].BT = heap[now / 2].BT;
        heap[now].AT = heap[now / 2].AT;
        heap[now].num=heap[now/2].num;

        now /= 2;

    }

    heap[now].BT = element.BT;
    heap[now].AT = element.AT;
    heap[now].num=element.num;

}

 

struct program DeleteMin() {

    int  child, now;
    struct program minElement, lastElement;
    minElement = heap[1];

    lastElement = heap[heapSize--];

    for (now = 1; now * 2 <= heapSize; now = child) {

        child = now * 2;

        if (child != heapSize && heap[child + 1].BT < heap[child].BT) {

            child++;

        }

        if (lastElement.BT > heap[child].BT) {

            heap[now].BT = heap[child].BT	;
            heap[now].AT = heap[child].AT	;
            heap[now].num=heap[child].num;

        } else

        {

            break;

        }

    }

    heap[now].BT = lastElement.BT;
    heap[now].AT = lastElement.AT;
    heap[now].num=lastElement.num;

    return minElement;

}
// devam is my name
 
void swap(struct program* xp, struct program* yp)
{
    struct program temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(struct program arr[], int n)
{
    int i, j;
    int  swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].AT > arr[j + 1].AT) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == 0)
            break;
    }
}
int main() {

    int number_of_elements;

    printf("SJF Scheduling :\nEnter number of programs: ");

    scanf("%d", &number_of_elements);

    int iter;
    struct program element;

    Init();

    printf("Enter the burst time and arrival time : ");

   
    struct program *arr=(struct program* )malloc(sizeof(struct program)*number_of_elements);

    for (iter = 0; iter < number_of_elements; iter++) {
        printf("\n");
        scanf("%d%d", &(element.BT),&(element.AT));
        element.num=iter+1;
        
        arr[iter]=element;

    }
    bubbleSort(arr,number_of_elements);
    // for (iter = 0; iter < number_of_elements; iter++) {

    //     printf("%d  %d %d \n", (arr[iter].BT),arr[iter].AT,arr[iter].num);
       

    // }
    int state =0;
    int arr_ind=0;
    int end;
    for (int i = 1; i < 1000; i++) {
        if(end==i) state =0;
        while(arr[arr_ind].AT==i){
            Insert(arr[arr_ind]);
            arr_ind++;
        }
        if(state==0){
            if(heapSize==0){
                continue;
            }
            struct program t= DeleteMin();
            printf("\nThe next program is : %d", t.num);
            end=i+t.BT;
            state =1;
        }
    }
    printf("\n");

    return 0;

}