#include<stdio.h>

#include<limits.h>

 

/*Declaring heap globally so that we do not need to pass it as an argument every time*/

/* Heap implemented  here is Min Heap */

 

int heap[1000000], heapSize;

// /*Initialize Heap*/

// void Init() {

//     heapSize = 0;

//     heap[0] = INT_MAX;

// }

 

/*Insert an element into the heap */

// void Insert(int element) {

//     heapSize++;

//     heap[heapSize] = element; /*Insert in the last place*/

//     /*Adjust its position*/

//     int now = heapSize;

//     while (heap[now / 2] < element) {

//         heap[now] = heap[now / 2];

//         now /= 2;

//     }

//     heap[now] = element;

// }

 

// int DeleteMax() {

   

//     int maxElement, lastElement, child, now;
//         maxElement = heap[1];

//     lastElement = heap[heapSize--]; 
//     for (now = 1; now * 2 <= heapSize; now = child) {
//         child = now * 2;
//         if (child != heapSize && heap[child + 1] > heap[child]) {
//             child++;
//         }
//         if (lastElement < heap[child]) {
//             heap[now] = heap[child];
//         }
//         else{
//             break;
//         }
//     }
//     heap[now] = lastElement;
//     return maxElement;

// }
int DeleteMax(){
    int ans=heap[1];
    int element=heap[heapSize--];
    int now = 1;
    
    int child=2;




    for(now=1;now*2<=heapSize;now=child){
        child=now*2;
        if(child!=heapSize && heap[child +1]<heap[child]){
            child++;       
        }
        if(element>heap[child]){
            heap[now]=heap [child];
        }
        else{
            break;
        }      
    }
    heap[now]=element ; 
    return ans; 




    // for (now = 1; now * 2 <= heapSize; now = child) {
    //     child = now * 2;
    //     if (child != heapSize && heap[child + 1] > heap[child]) {
    //         child++;
    //     }
    //     if (element < heap[child]) {
    //         heap[now] = heap[child];
    //     }
    //     else{
    //         break;
    //     }
    // }
    // heap[now] = element;
    // return ans;
    
}


void Init(){
    heapSize=0;
    heap[0]=-INT_MAX;
}
void Insert(int n){
    heapSize++;
    int now =heapSize;
    // heap[heapSize]=n;
    int element=n;
    while(heap[now/2]>element){
        heap[now]=heap[now/2];
        now/=2;
    }
    heap[now]=element;
    return;
}



bool are_same(int*temp1,int*temp2,int k){
    for(int i=0;i<k;i++)
        if(temp1[i]!=temp2[i])
        return false;
        
    return true;   
}

    bool checkInclusion(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        if(m>n) return false;
        int temp1[256]={0},temp2[256]={0};
        for(int i=0;i<m;i++){
            temp1[s1[i]]++;
            temp2[s2[i]]++;
        }
        for(int i=m;i<n;i++){
            if(are_same(temp1,temp2,256))
            return true;

            temp2[s2[i-s1.length()]]--;
            temp2[s2[i]]++;
        }
    return false;
}

int main() {

    int number_of_elements;

    printf("Program to demonstrate Heap:\nEnter the number of elements: ");

    scanf("%d", &number_of_elements);

    int iter, element;

    Init();

    printf("Enter the elements: ");

    for (iter = 0; iter < number_of_elements; iter++) {

        scanf("%d", &element);

        Insert(element);

    }
    int k;
    // printf("\nEnter k : ");
    // scanf("%d",&k);
    int num;
    for (iter = 0; iter < number_of_elements; iter++) {

       num = DeleteMax();
       printf("\nThe kth Max Element is : %d",num);

    }
    // printf("The kth Max Element is : %d",num);

    printf("\n");

    return 0;

}
