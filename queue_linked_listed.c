#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * Next;
};
 struct Node * r = NULL;
struct Node * f = NULL;

void linked_list_traversal(struct Node *ptr){
        while(ptr != NULL){
            printf("%d\n", ptr->data);
            ptr = ptr->Next;
        }
};

void enqueue(int val){
   struct Node * n =  (struct Node *) malloc(sizeof(struct Node)); 
    if(n==NULL){
        printf("Queue is full!");
    }
    else{
        n->data = val;
        n->Next = NULL;
        if(f == NULL){
            f=r=n;
        }
        else{
          r->Next = n;
          printf("address of r: %d\n", n);
          r=n;
        }


    }
}
int dequeue(){
    int val = -1;
    struct Node * ptr = f;
    if(f == NULL){
        printf("Queue is empty!");
    }
    else{
    f = f->Next;
    printf("address of n : %d\n", f);
    val = ptr->data;
    free(ptr);  
    }
    return val;
    }


int main(){
   
   enqueue(12);
   enqueue(13);
//    printf("dequeued :%d\n", dequeue());
   printf("dequeued :%d\n", dequeue());
  linked_list_traversal(f);
        
    return 0;
}