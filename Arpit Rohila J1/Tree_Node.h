#include<stdio.h>
#include <stdlib.h>

struct Tree_Node{
    struct Tree_Node *left;
    struct Tree_Node *right;
    char ch;
};

struct Tree_Node* create_Node();
struct Tree_Node* create_With_cild(struct Tree_Node * left , struct Tree_Node *right);