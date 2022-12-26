#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 200
typedef struct node node;
 
/**
 * Creating a structure for a node of tree
**/
struct node {
    int data;
    node *left;
    node *right;
};
 
/**
 * Helper function to create new node in the tree
**/
node* newNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
/**
 * Function to create new stack of nodes
**/
node **createStack(int *top) {
    node **stack = (node**)malloc(sizeof(node*)*MAX_QUEUE_SIZE);
    *top = 0;
    return stack;
}
 
/**
 * Function to add (push) a new nodes in stack 
**/
void push(node **stack, int *top, node *root) {
    stack[++(*top)] = root;
}
 
/**
 * Function to remove (pop) a new nodes from the stack 
**/
node* pop(node **stack, int *top) {
    (*top)--;
    return stack[*top + 1];
}
 
void preOrderIterative(node *root) {
 
    if(root==NULL) return;
    int top;
    node **stack = createStack(&top);
    node *temp;
    push(stack, &top, root);
    while(top>0) {
        temp = pop(stack, &top);
        printf("%d ", temp->data);
        if(temp->right!=NULL) push(stack, &top, temp->right);
        if(temp->left!=NULL) push(stack, &top, temp->left);
        // printf("\n $$$$ %d", temp->data);
    }
}
 
void postOrderIterative(node *root) {
 
    if(root==NULL) return;
    int top;
    node **stack = createStack(&top);
    int top2;
    node **stack2 = createStack(&top2);
    node *temp;
    push(stack, &top, root);
    while(top>0) {
        temp = pop(stack, &top);
        push(stack2, &top2, temp);
        if(temp->left!=NULL) push(stack, &top, temp->left);
        if(temp->right!=NULL) push(stack, &top, temp->right);
    }
 
    while(top2>0) {
        printf("%d ", pop(stack2, &top2)->data);
    }
}
void inOrderIterative(node *root) {
 
    if(root==NULL) return;
    int top, done=0;
    node **stack = createStack(&top);
    node *temp=root;
    // push(stack, &top, temp);
    while(!done) {
        if(temp!=NULL) {
            push(stack, &top, temp);
            temp=temp->left;
        }
        else {
            if(top>0) {
                temp = pop(stack, &top);
                printf("%d ", temp->data);
                temp = temp->right;
            }
            else {
                done = 1;
            }
        }
    }
 
 
}
 
/**
 * Main Driving Function
**/
void main() {
    
    node* a = newNode(50);
    a->left = newNode(30);
    a->right = newNode(20);
    a->left->left = newNode(10);
    a->left->right = newNode(60);
    a->right->left = newNode(70);
    a->left->right->left = newNode(80);
 
        //         50
        //       /    \
        //     30      20
        //    /  \    /   
        // 10    60  70    
        //      /
        //     80
    
    printf("\nPre-Order Iterative: ");
    preOrderIterative(a);
    printf("\nIn-Order Iterative: ");
    inOrderIterative(a);
    printf("\nPost-Order Iterative: ");
    postOrderIterative(a);
 
}
