#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
struct lifo {
    int top;
    int a[MAXSIZE];
};
typedef struct lifo stack;
void createStack(stack *s){
    s->top=-1;

}
void push(stack *s,int val){
    if(s->top==MAXSIZE-1){
        printf("\nStack Full. Cant push\n");
        exit(-1);
    }
    s->top++;
    (s->a)[s->top]=val;
}
int pop(stack*s){
    if(s->top==-1){
        printf("\nStack full.Cant pop\n");
        exit(-1);
    }
    int k=(s->a)[s->top];
    s->top--;
    return k;
}
int main(){
    stack * s=(stack*)malloc(sizeof(stack));
    createStack(s);
    push(s,9);
    push(s,8);
    push(s,7);
    push(s,6);
    push(s,5);
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));


    return 0;
}