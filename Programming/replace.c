#include<stdio.h>
//#define initial ''
void replace() {
    putchar(' ');
} 
int main()
{   
    char c,last_iter;
    

    while ((c=getchar())!=EOF) {

        if (last_iter==' ' && c==' ') {
            continue;

        }
        
        else {
            putchar(c);
        }
        

        


        last_iter=c;


    }
    
    return 0;
}