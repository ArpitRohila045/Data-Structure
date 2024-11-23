#include<stdio.h>
#include "Tree_Node.h"

struct stack{
    int top;
    struct Tree_Node *arr;
    int size;
};

struct Tree_Node* create_Node();

struct stack* create_Stack(int size);

int is_Empty(struct stack **st);

void push(struct stack **st , struct Tree_Node *node);

struct Tree_Node pop(struct stack **st);
