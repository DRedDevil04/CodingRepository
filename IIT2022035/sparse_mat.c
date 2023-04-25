#include <stdio.h>
#include <stdlib.h>

struct node {
    int cnum;
    int val;
    int rnum;
    struct node *next;
};
struct row {
    
    int rnum;

    struct node *cols;
    struct row *next;
};
void insert_sorted(struct row **head,struct node *element){

    struct row *ptr=*head;
    struct row *prev=*head;

    for(ptr=*head;ptr!=NULL;ptr=ptr->next){

        if(prev==*head && (ptr->rnum)>(element->rnum) && ptr==*head){
                struct row * r=(struct row*)malloc(sizeof(struct row));
                r->rnum=element->rnum;
                r->cols=element;
                r->next=&(**head);
                *head=r;
                return;

            }
        if((ptr->rnum)==(element->rnum)){
            struct node *p=ptr->cols;
            for(;p->next!=NULL;p=p->next){
                continue;
            }
            p->next=element;
            element->next=NULL;
            return;

        }
        else if((ptr->rnum)<(element->rnum)){
            
            if(ptr->next==NULL){
                struct row * r=(struct row*)malloc(sizeof(struct row));
                ptr->next=r;
                r->rnum=element->rnum;
                r->next=NULL;
                r->cols=element;       
                return;
            }
            struct row * r=(struct row*)malloc(sizeof(struct row));
                
            r->rnum=element->rnum;
                
            r->cols=element;

            prev->next=r;
            r->next=ptr;
            return;
            // prev=ptr;
            // continue;

        }
        else{
            //  struct row * r=(struct row*)malloc(sizeof(struct row));
                
            //     r->rnum=element->rnum;
                
            //     r->cols=element;

            // prev->next=r;
            // r->next=ptr;
            // return;
            prev=ptr;
            continue;

        }

    }
    
}
void CreateSparseMatrix(struct row **X,int row,int col,int nvz){
    
    struct  node *p=(struct node *)malloc(sizeof(struct node));
    // scanf("%d %d %d", &(p->cnum), &(p->rnum), &(p->val));
    p->cnum=row;
    p->rnum=col;
    p->val=nvz;
    p->next=NULL;
    if(*X==NULL){
        struct row * ptr=(struct row*)malloc(sizeof(struct row));
        ptr->rnum=p->rnum;
        ptr->next=NULL;
        ptr->cols=p;
        *X=ptr;
        
    } 
    else{
        insert_sorted(X,p);
    }

    
}

void print_list(struct row *head){
    printf("HHEHE %d",head->cols->cnum);
    struct row *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        struct node * p=ptr->cols;
        for(;p!=NULL;p=p->next){
            printf("\nElement is row col  %d  %d",p->rnum,p->cnum);
        }
        
    }
}
void multiply( struct row **A,struct row **B, struct row **prod,int m){
    //Here we are considering that the passed matrix is already the transposed matrix
    //IF NOT
    //We can use the transpose function(which i couldnt get the time to code)
    // transpose(B);

    struct row *ra=*A,*rk=*B;
    if(ra==NULL || rk==NULL){
            return;
        }
    for(;ra!=NULL;ra=ra->next){
        struct row* rb=*B;
        for(;rb!=NULL;rb=rb->next){

            
            for(struct node *ta=ra->cols;ta!=NULL;ta=ta->next){
                struct node * mult=NULL;
                int flag=0;
                for(struct node *tb=rb->cols;tb!=NULL;tb=tb->next){
                    if(ta->cnum==tb->cnum){
                        if(flag){
                            mult->val+=ta->val*tb->val;
                        }
                        else{
                            mult=(struct node *)malloc(sizeof(struct node));
                            mult->cnum=rb->rnum;
                            mult->rnum=ra->rnum;
                            mult->val+=ta->val*tb->val;
                            flag=1;
                        }
                    }
                }
                // CreateSparseMatrix(prod,mult->cnum,mult->rnum,mult->val);
                if(mult!=NULL){
                    CreateSparseMatrix(prod,mult->cnum,mult->rnum,mult->val);
                    free(mult);
                } 
            }

        }
    }
}
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=m;j++){



//         if(i==ra->rnum && i==rb->rnum){
//             struct node *ca=ra->cols;
//             for(;ca!=NULL;ca=ca->next){
//                 struct node *cb=rb->cols;
//                 for(;cb!=NULL;cb=cb->next){
//                     if(ca->cnum==cb->cnum){
//                         struct node * mult=(struct *node)malloc(sizeof(struct node));
//                         mult->val=(ca->val)*(cb->val);
//                         mult->rnum=ca->rnum,mult->cnum=ca->cnum;
//                         mult->next=NULL;
//                         if(*prod==NULL){
//                             struct row * ptr=(struct row*)malloc(sizeof(struct row));
//                             ptr->rnum=p->rnum;
//                             ptr->next=NULL;
//                             ptr->cols=mult;
//                             *prod=ptr;
//                         }
//                         else{

//                         }
//                     }
//                 }
//             }
//         }
//     }
// }


void DisplaySparseMatrix(struct row *X, int m){
    printf("\n");
    struct row* ptr=X;
    for(int i = 1; i <= m; i++){
        if(ptr==NULL){
            for(int j=1;j<=m;j++){
                printf("0 ");
            }
            printf("\n");
            continue;
        }
        if(ptr->rnum==i){
            struct node* rp=ptr->cols;
            for(int j = 1; j <= m; j++){
                if(rp==NULL){
                    while(j<=m){
                        printf("0 ");
                        j++;
                    }
                    continue;
                }
                while(rp->cnum!=j && j<=m){
                    printf("0 ");
                    j++;
                }
                printf("%d ",rp->val);
            
                
                rp=rp->next;
                continue;
                
        }
        ptr=ptr->next;
        }
        else{
            for(int j=1;j<=m;j++){
                printf("0 ");
            }

        }
        
        printf("\n");
    }
}
// void add(struct node **A, struct node **B){
//     struct node * ptr= *B;
//     struct node * ptr2= *A;
//     for(;ptr!=NULL;ptr=ptr->next){
//         int flag=0;
//         for(ptr2=*A;ptr2!=NULL;ptr2=ptr2->next){
//             if(ptr->i==ptr2->i && ptr2->j==ptr->j){
//                 ptr2->val+=ptr->val;
//                 flag=1;
//                 break;
//             }

//         }
//         if(!flag){


//             struct node *p=(struct node *)malloc(sizeof(struct node));
//             p->i=ptr->i;
//             p->j=ptr->j;
//             p->val=ptr->val;
//             p->next=*A;
//             (*A)=p;
//     }
//     }   
// }
int main(){
    int m,m2, x;
    printf("Enter dimension of the 2 square matrices:");
    scanf("%d", &m);
    printf("Enter total number of non-zero vals: \n");
    scanf("%d", &x);
    
    struct row* A = NULL; 
    
    printf("Enter all non-zero vals:\n");
    for(int i = 1; i <= x; i++){
        int rn,cn,nvz;
        printf("Enter row number, column number and non-zero val:\n");
        scanf("%d %d %d", &rn, &cn, &nvz);
        CreateSparseMatrix(&A,rn,cn,nvz);
    }
    print_list(A);
    printf("\nSparse Matrix 1: \n");
    
    DisplaySparseMatrix(A, m);


    printf("Enter total number of non-zero vals in sparse matrix 2: \n");
    scanf("%d", &x);
    
    struct row* B = NULL; 
    
    printf("Enter all non-zero vals:\n");
    for(int i = 1; i <= x; i++){
        int rn,cn,nvz;
        printf("Enter row number, column number and non-zero val:\n");
        scanf("%d %d %d", &rn, &cn, &nvz);
        CreateSparseMatrix(&B,rn,cn,nvz);
    }
    print_list(B);
    printf("\nSparse Matrix 1: \n");
    
    DisplaySparseMatrix(B, m);

    struct row* prod=NULL;
   
    // add(&A,&B);
    // print_list(A);
    // printf("\nSparse Matrix Added: \n");
    // DisplaySparseMatrix(A,m,n);
    multiply(&A,&B, &prod,m);
    // print_list(A);
    printf("\nSparse Matrix multiplied: \n");
    DisplaySparseMatrix(prod,m);
    return 0;
}