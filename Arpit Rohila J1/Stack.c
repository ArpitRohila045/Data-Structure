#include<stdio.h>
#include "Tree_Node.h"
#include "stack.h"

struct Tree_Node* create_Node(){
    struct Tree_Node *temp = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

struct stack* create_Stack(int size){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->arr = (struct Tree_Node*)calloc(size, sizeof(struct Tree_Node));
    temp->size = size;
    temp->top = -1;
    return temp;
}

int is_full(struct stack **st){
    return (*st)->top == (*st)->size ? 1 : 0;
}

int is_Empty(struct stack **st){
    return (*st)->top == (*st)->size ? 1 : 0;
}

void push(struct stack **st , struct Tree_Node *node){
    if(is_full(&(*st))){
        printf("Stack OverFlow !\n");
    }
    int top = (*st)->top;
    (*st)->top++;
    (*st)->arr[++top] = *node;
}

struct Tree_Node pop(struct stack **st){
    if(is_Empty(&(*st))){
        printf("Stack UnderFlow !\n");
    }
    struct Tree_Node temp = (*st)->arr[(*st)->top];

    return (*st)->arr[(*st)->top--];
}
