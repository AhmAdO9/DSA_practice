#include<stdio.h>
#include<stdlib.h>


void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
};

// void selection_sort(int * A, int n){

//         for(int i=0; i < n-1; i++){
//             int temp, indexMin;
//             indexMin = i;
//             for(int j=i+1; j < n; j++){
//                 if(A[indexMin] > A[j]){
//                     indexMin = j;
//                 }
//             }
//             temp = A[i];
//             A[i] = A[indexMin];
//             A[indexMin] = temp;
            
//         }
// }


void selection_sort(int * A, int n){
    for(int i=0; i<n-1; i++){
        int indexMin = i; 
        int temp;
        for(int j=i+1; j< n; j++){
            if(A[indexMin]>A[j]){
                indexMin = j;
            }
        }
            temp = A[i];
            A[i] = A[indexMin];
            A[indexMin] = temp;
    }

}



int main(){
    int A[]= {4,3,2,1};
    int n = 4;
    printArray(A, n);
    selection_sort(A, n);
    printArray(A, n);
    return 0;
} 