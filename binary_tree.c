#include<stdio.h>
#include<stdlib.h>
// #include<malloc.h>


struct node{
    int data;
    struct node * left;
    struct node * right;
    

};

struct node * createNode(int data){
    struct node * n;
    n =  (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;

};

void preOrder(struct node * root){
    if(root != NULL){
        printf("%d", root->data);  
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);  
    }

}
void inOrder(struct node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d", root->data);  
        inOrder(root->right);
    }
 
}

// int isBST(struct node * root){
//     static struct node * prev = NULL;
//     if(root != NULL){
//         if(!isBST(root->left)){
//             return 0;
//         }
//         if(prev != NULL && root->data <= prev->data ){
//             return 0;
//         }
//         prev = root;
//             return isBST(root->right);
//     }
//     else{
//         return 1;
//     }
 
// }
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


struct node* Search(struct node* root, int key){
            if(root == NULL){
                return root;
            }
            if(root->data == key){
                return root;
            }
            
            else if(root->data > key){
                return Search(root->left, key);
            }
            else{
                return Search(root->right, key);
            }
}

void insertion(struct node * root, int key){
    struct node * prev = NULL;
        while(root != NULL){
        prev = root;
            if(key == root->data){return;}
            if(root->data > key ){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        printf("%d", prev->data);
        // struct node * new = createNode(key);
        // if(prev->data < key){
        //     prev->right=new;
        // }
        // else{
        //     prev->left = new;
        // }

}

struct node* inOrderPredecessor(struct node* root){
    root = root->left;
        while(root!=NULL){
            if(root->right == NULL){
                break;
            }
        root = root->right;
        }
        return root;
}


struct node* deletion(struct node * root, int key){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL && root->left == NULL){free(root);return NULL;}


            if(key < root->data){
                root->left = deletion(root->left, key); 
            }
            else if(key>root->data){
                root->right = deletion(root->right, key);
            }
            else{

            ipre = inOrderPredecessor(root);
            root->data = ipre->data;
            root->left =  deletion(root->left, ipre->data);
            }

    return root;      
}



int main(){

struct node * p = createNode(8);
struct node * p1 = createNode(6);
struct node * p2 = createNode(9);
struct node * p3 = createNode(5);
struct node * p4 = createNode(7);

    //     8
    //    / \
    //   6   9
    //  / \
    // 5   7


p->left = p1;
p->right = p2;
p1->left = p3;
p1->right = p4;


// struct node * p = (struct node*)malloc(sizeof(struct node));
// struct node * p1 = (struct node*)malloc(sizeof(struct node)); 
// struct node * p2 = (struct node*)malloc(sizeof(struct node));

// p->data = 2;
// p->left =  p1;
// p->right = p2;

// p1->data = 3;
// p1->left =  NULL;
// p1->right = NULL;

// p2->data = 4;
// p2->left =  NULL;
// p2->right = NULL;
// struct node * p5 = createNode(2);
// struct node * p6 = createNode(4);

// p2->left = p5;
// p2->right = p6;


// preOrder(p);
// printf("\n");
// printf("%d", (isBST(p)));
// printf("\n");
// postOrder(p);


// struct node * n = Search(p,5);
// if(!(n == NULL)){
// printf("%d", n->data);
// }
// else{
//     printf("Element not found!");
// }



// insertion(p,4);
// inOrder(p);
// printf("%d", (*deletion(p,6)));







    return 0;
}