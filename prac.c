#include<stdio.h>
#include<stdlib.h>

struct array{
    int * arr;
};

void printArray(struct array * A, int n){
    for(int i = 0; i < n-1; i++){
        printf("%d ", A->arr[i]);
    }
};

void traverse(int *A, int n, struct array * ptr){
    ptr->arr = (int*)malloc(n*sizeof(int));
        for(int i=0; i<n; i++){
            if((i+1)>=n){return;}
            else{int c = abs(A[i+1]-A[i]);
                ptr->arr[i] = c;
            }
        }
}

int main(){
struct array * ptr = (struct array*)malloc(sizeof(struct array));
int A[]= {73,74,75,71,69,72,76,73}; 
traverse(A,8, ptr);
printArray(ptr, 8);
 return 0;
}