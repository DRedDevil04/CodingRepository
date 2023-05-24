/*Devam Desai
IIT2022035 File sorting */






#include <stdio.h>
#include <stdlib.h>



#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubb(int arr[], int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if (arr[j+1] < arr[j]) swap(&arr[j], &arr[j+1]);
            // printf("%\n",j);
        }
    }
}

int main(){
    srand(time(0));
    FILE *fptr = fopen("devam_rand_nums.txt", "w+");
    if (fptr == NULL){
        printf("File couldnt be created.\n");
        exit(-1);
    }

    for (int i = 0; i<100000; i++){
        fprintf(fptr,"%d ",rand());
    }
    fseek(fptr,0,SEEK_SET);
    int *arr[100];
    for (int i = 0; i<100; i++){
        arr[i] = (int *)malloc(1000*sizeof(int));
        for (int j = 0; j<1000; j++){
            fscanf(f, "%d ", &arr[i][j]); 
        }
    }
    for (int i = 0; i<100; i++){
        bubb(arr[i],1000);
    }
    FILE *fout = fopen("devam_sorted_nums.txt", "w+");
    if (out == NULL){
        printf("File couldnt be created\n");
        exit(-1);
    }
    int *ind = (int *)calloc(100, sizeof(int));
    int *posi, min = __INT_MAX__;
    // for (int i = 0; i<100; i++) 
    // printf("%d ", arr[i][0]);
    // printf("\n");
    // printf("\n");
    // printf("\n");
    for (int i = 0; i<100000; i++){
        min = __INT_MAX__;
        for (int j = 0; j<100; j++){   
            if (ind[j] == -1) {
            	continue; 
            }
            else{
                if (arr[j][ind[j]] < min){
                    min = arr[j][ind[j]];
                    posi = ind+j;
                }
            }
        }
        (*posi)++;
        if (*posi == 1000) (*posi) = -1;
        fprintf(fout,"%d ",min);
    }
    fclose(fptr);
    fclose(fout);
    return 0;
}