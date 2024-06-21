/*Devam Desai
IIT2022035 LA5 P2(i)*/
// Running time: O(n)
#include<stdio.h>
void swap(int *,int *);
  

int main()
{
    
    int n, m, max, nextmax, i , num;
    
    printf("Give n:");
    scanf("%d",&n);
    printf("\nn = %d \n",n);
      
    scanf("%d%d",&max,&nextmax);
    if(max<nextmax) swap(&max,&nextmax); 
    
    for(i=1; i<=n-2; i++){
        scanf("%d",&num);
        if(num >= max){
            nextmax=max; max = num;}
        else if(num>nextmax)
                nextmax = num;
        
    }
    
    printf("\nMAX = %d, NEXTMAX=%d \n",
           max,nextmax);
}

void swap(int *i,int *j)

{
    int temp;
    temp =*i;
    *i=*j;
    *j=temp;
}






