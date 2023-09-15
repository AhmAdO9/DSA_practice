#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
};



void merge(int * A, int low, int mid, int high, int * B){
              
                int i = low;
                int j = mid+1; 
                int k = low;


                while(i<=mid && j<=high){
                    if(A[i]>A[j]){
                        B[k]=A[j];
                        k++;
                        j++;
                    }
                    else{
                        B[k]=A[i];
                        k++;
                        i++;
                    }
                };
                    while(i<=mid){
                        B[k]= A[i];
                        i++;
                        k++;
                    };
                    while(j<=high){
                        B[k]= A[j];
                        j++;
                        k++;
                    }
                    for(i=0; i<=high; i++){
                        A[i]=B[i];
                        
                    }
                }


                
void mergeSort(int * A, int low, int high,int * B){
    float mid; 
    if(low<high){
        mid = (low+high)/2;
        mergeSort(A, low, mid, B);
        mergeSort(A, mid+1, high, B);
        merge(A, low,mid, high, B);
    }
}


int main(){

    int A[] = {7,8,9,1,2,3};
    int B[6];
    int n = 6;
    int low=0;
    int high = n-1;
    mergeSort(A,low,high,B);
    printArray(A, 6);
    return 0;
}