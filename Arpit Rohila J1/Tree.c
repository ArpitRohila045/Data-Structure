#include<stdio.h>
#include<stdlib.h>
#include "Tree_Node.h"

struct Stack{
    struct Tree_Node *left;
    struct Tree_Node *right;
    int data;
};