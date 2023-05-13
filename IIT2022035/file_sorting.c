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
    FILE *f = fopen("input.txt", "w+");
    if (f == NULL){
        printf("File could not be opened.\n");
        exit(-1);
    }

    for (int i = 0; i<100000; i++){
        fprintf(f, "%d ", rand());
    }
    fseek(f, 0, SEEK_SET);

    int *arrays[100];




    //printf("%d",arrays[0])
    for (int i = 0; i<100; i++){
        arrays[i] = (int *)malloc(1000*sizeof(int));
        for (int j = 0; j<1000; j++){
            fscanf(f, "%d ", &arrays[i][j]); 
        }
    }
    for (int i = 0; i<100; i++){
        bubb(arrays[i],1000);
    }
    FILE *out = fopen("output.txt", "w+");
    if (out == NULL){
        printf("File could not be opened.\n");
        exit(-1);
    }
    int *indices = (int *)calloc(100, sizeof(int));
    int *posi, min = __INT_MAX__;
    // for (int i = 0; i<100; i++) 
    // printf("%d ", arrays[i][0]);
    // printf("\n");
    // printf("\n");
    // printf("\n");
    for (int i = 0; i<100000; i++){
        min = __INT_MAX__;
        for (int j = 0; j<100; j++){
            // printf("%d ", arrays[j][indices[j]]);
            if (indices[j] == -1) 
            	continue; 
            else{
                if (arrays[j][indices[j]] < min){
                    min = arrays[j][indices[j]];
                    posi = &(indices[j]);
                }
            }
        }
        (*posi)++;
        if (*posi == 1000) (*posi) = -1;
        fprintf(out, "%d ", min);
    }
    

    fclose(f);
    fclose(out);
}