#include<stdio.h>
#include<stdlib.h>

void printArray(int * A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
};



int biggest(int * A, int n){
            int i = 0;
            int c = A[i];
            int j;
            for(j=1; j<=n-1; i++){
                if(c < A[j]){
                     c = A[j];
                     j++;
                }
                else{
                    j++;
                    continue;
                }

            };
           return c;

}
void countSort(int * A, int c, int n){
        int B[c];
        for(int i=0; i<=c-1; i++){
         
            B[i]=0;
        }
        for(int i = 0; i<=n-1; i++){
   
              int index =  A[i];
              B[index]++;
        }

        int i = 0;
        int j=0;

        while(i<=c-1){

            if(B[i]>1){
                B[i]=B[i]-1;
                A[j] = i;
                j++;
                
            }

            else if(B[i]==1){
                B[i]=B[i]-1;
                A[j] = i;
                j++;
                i++;
            }
            else{
                i++;
            }
            };
        }


int main(){
    int A[] = {7,2,4,8,0,0,0,0,0,0,0,1};
    int n = 12;
    int h = biggest(A,n);
    countSort(A, h+1, n);
    printArray(A,n);
    return 0;
}