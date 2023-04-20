#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int roll;
    int cgpa;
}student;
void entry(student *p)
{
    printf("\nEnter value");
    scanf("%s",&(p->name));
    scanf("%d",&(p->roll));
    scanf("%d",&(p->cgpa));
     
}

int main()
{   student *ptr;

    ptr=(student *)malloc(2*sizeof(student));
        for(int i=0;i<2;i++)
         entry(ptr+i);
        for(int i=0;i<2;i++)
    {
        printf("%s",(ptr+i)->name);
        printf("%d",(ptr+i)->roll);
        printf("%d",(ptr+i)->cgpa);
    }
    return 0;
}