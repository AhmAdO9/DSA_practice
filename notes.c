#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char* arr;
};

int stack_top(struct stack * sp){
    return sp->arr[sp->top];
};
int is_empty(struct stack * sp){
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
};

int is_full(struct stack * sp){
    if(sp->top == sp->size-1){
        return 1;
    }
    else{
        return 0;
    }
};

void push(struct stack * sp, char val){
    if(is_full(sp)){
        printf("Stack is full!");
    }
    else{
        sp->top++;
        sp->arr[sp->top]= val;
    }
    
};

char pop(struct stack * sp){
   if(is_empty(sp)){
    printf("Stack is already empty");
    return -1;
   } 
   else{
    char val = sp->arr[sp->top];
    sp->top--;
    return val;
   }
}

int precedence(char ch){
    if(ch == '*'|| ch== '/'){
        return 3;
    }    
    else if(ch =='-'|| ch =='+'){
        return 2;
    }
    else return 0;
}

int is_operator(char ch){
    if(ch == '*'|| ch== '/' || ch =='-'|| ch =='+'){
        return 1;
    }    
    else {
        return 0;
}
};
char* infix_to_postfix(char * infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top=-1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while(infix[i]!='\0'){
        if(!is_operator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(precedence(infix[i])>precedence(stack_top(sp))){
            push(sp,infix[i]);
            i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
    }

    while (!is_empty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfixfix is %s",infix_to_postfix(infix));
    return 0;
}
