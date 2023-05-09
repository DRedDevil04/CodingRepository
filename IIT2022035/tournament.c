
// #include <stdio.h>
// int maxi(int ,int);
// int main()
// {
//     int tourn[100],i,n;
    
//     /* Read N */
    
//     printf("Give n:");
//     scanf("%d",&n);
//     printf("\n n = %d \n",n);
    
//     for(i=n; i<=2*n-1; i++){
//         scanf("%d",&tourn[i]);
//     }
//     /* Compute the tournament */
        
//     for(i=2*n-2;i>1; i=i-2){
//         tourn[i/2] = maxi(tourn[i],tourn[i+1]);
//     }
//         /* Print Result */
        
//     for(i=1; i<=2*n-1; i++){
//         printf("%d %d",tourn[i],i);
//         printf("\n");}  
    
// }
    
// int maxi(int i ,int j)
// {
//     if(i>j) return(i);
//     else return(j);
// }
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int* arr=(int *)malloc(sizeof(int)*2*n);
    for (int i = n; i<=2*n-1; i++){
        scanf("%d", &arr[i]);
    }
    for (int i=n-1;i>=1;i--){
        arr[i]=(arr[2*i]>arr[2*i+1])?arr[2*i]:arr[2*i+1];
        // printf("%d %d \n",i,arr[i]);
    }
    printf("\n");
    for (int i = 1; i<=2*n-1; i++){
        printf("%d ", arr[i]);
    }
    printf("\nMAX: %d\n",arr[1]);



    //downward traversal
    int max=arr[1];
    arr[1]=-1;
    int i =1;
    for(i=1;i<2*n;){
        if(arr[2*i]==max){
            arr[2*i]=-1;
            i=2*i;
            // printf("%d %d\n",i,2*i);
            continue;
        }
        else{
            arr[2*i+1]=-1;
            i=2*i+1;
            // printf("%d %d\n",i,2*i);
        }
    }
    // printf("\n");
    // for (int i = 1; i<=2*n-1; i++){
    //     printf("%d ", arr[i]);
    // }
    for (int i=n-1;i>=1;i--){
        arr[i]=(arr[2*i]>arr[2*i+1])?arr[2*i]:arr[2*i+1];
        // printf("%d %d \n",i,arr[i]);
    }
    // printf("\n");
    // for (int i = 1; i<=2*n-1; i++){
    //     printf("%d ", arr[i]);
    // }
    printf("\nNEXT MAX: %d\n",arr[1]);
    return 0;

}