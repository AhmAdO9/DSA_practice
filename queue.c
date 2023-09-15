#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isfull(struct queue * q){
    if((q->r+1)% (q->size) == q->f){
        return  1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct queue * q){
    if(q->r == q->f){
        return 1;
    }
    else{
        return 0;
    }

}

int dequeue(struct queue * q){
    if(isEmpty(q)){
        printf("Queue empty!");
    }
    else{
        q->f = (q->f+1)%q->size;
        int a = q->arr[q->f];
        return a;
}
}

void enqueue(struct queue * q, int val){
    if(isfull(q)){
        printf("Queue overflow!");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Done!\n");
    }
}


int main(){
    struct queue * q = (struct queue *) malloc(sizeof(struct queue));
    q->size = 3;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size * sizeof(int)); 
    enqueue(q,2);
    enqueue(q,2);
    dequeue(q);
    enqueue(q,2);
    

    return 0;
}