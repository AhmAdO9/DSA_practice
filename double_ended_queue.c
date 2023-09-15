#include<stdio.h>
#include<stdlib.h>


struct Queue{
    int * arr;
    int r;
    int f;
    int size;
};

int isFull(struct Queue * q){
        if(q->r == q->size - 1){
            return 1;
        }
        else{
            return 0;
        }
};

int isEmpty(struct Queue * q){  
        if(q->r == -1){
            return 1;
        }
        else{
            return 0;
        }
};

void enqueue_R(struct Queue * q, int val){
            if(isFull(q)){
                printf("Queue is full!");
            }
            else{
                q->r++;
                q->arr[q->r] = val;
                printf("Done!\n");
            }
};

void dequeue_R(struct Queue * q){
            int val;
         if(isEmpty(q)){
            printf("Queue is Empty!");
         }   
         else{
            val = q->arr[q->r];
            q->r--;
            printf("Dequeued value is: %d\n", val); 
         }
        }




 
int main(){

    struct Queue * q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 10;
    q->r = -1;
    q->f = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    enqueue_R(q,1);
    enqueue_R(q,12);
    dequeue_R(q);
    dequeue_R(q);
    dequeue_R(q);
    return 0;
}