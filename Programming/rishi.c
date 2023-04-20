#include <stdio.h>
int main(void) {
// your code goes here
int t,n;
scanf("%d",&t);
for(int i=0;i<t;i++){
   scanf("%d",&n);
   int a[n];
   for(int j=0;j<n;j++){
       scanf("%d",&a[j]);
   }
   for(int k=0;k<n;k+=2){
       if(a[k]==0 && a[k+1]==0) printf("A");
       else if(a[k]==0 && a[k+1]==1) printf("T");
       else if(a[k]==1 && a[k+1]==0) printf("C");
       else if(a[k]==1 && a[k+1]==1) printf("G");
   }
   printf("\n");
}
return 0;
}