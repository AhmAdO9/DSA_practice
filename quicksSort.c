#include<stdio.h>
#include<stdlib.h>



void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
};

int partition(int * A, int low, int high)
{
                int i = low + 1;
                int j = high;
                int temp;

            do{

                while(A[i]<A[low]){
                    i = i+1;
                }

                while(A[j]>A[low]){
                    j = j-1;
                }
                
                if(i<j){
                    temp = A[i];
                    A[i]=A[j];
                    A[j] = temp;
                }
                
            } while(i<j);

            temp = A[low];
            A[low] = A[j];
            A[j] = temp;
            return j; 
}

void quickSort(int * A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low , partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main(){
        int A[] = {2,1};
    int n = 2;
    printArray(A, n);
    quickSort(A,0, n-1);
    printArray(A, n);

       return 0;
}