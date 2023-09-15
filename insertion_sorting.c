#include<stdio.h>
#include<stdlib.h>




void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
};

void insertion_sort(int * A, int n){
            for(int i=0; i<n-1; i++){
                int key = A[i+1];
                for(int j=i; j >=0; j--){
                    if(A[j]>key){
                    A[j+1] = A[j];
                    A[j] = key;
                    }
                    else{
                        break;
                    }
                } 
            }
}

int main(){

    int A[] = {2,6,4,1,7,9,0};
    int n = 7;
    printArray(A, n);
    insertion_sort(A, n);
    printArray(A, n);

    return 0;
}