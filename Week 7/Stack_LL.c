#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct LinkedList{
    struct Node *Top;
    int size;
};

struct LinkedList* create(){
    return (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
};

void Push(struct LinkedList **list, int data){
    struct Node *temp = (struct Node*)calloc(1,sizeof(struct Node));
    temp->data = data;

    if((*list)->Top == NULL){
        (*list)->Top = temp;
        (*list)->size++;
        return -1;
    }
    temp->next = (*list)->Top;
    (*list)->Top = temp;
    (*list)->size++;
}

int Pop(struct LinkedList **list){
    if((*list)->Top == NULL){
        printf("Stack Under flow!");
        return;
    }
    int data = (*list)->Top->data;
    (*list)->Top = (*list)->Top->next;
    return data;
}

int main(){

    struct LinkedList *list = create();
    Push(&list , 50);
    Push(&list , 60);
    Push(&list , 70);
    Push(&list , 80);
    Push(&list , 90);
    Push(&list , 100);

    printf("Popped element : %d\n" , Pop(&list));
    printf("Popped element : %d\n" , Pop(&list));
    printf("Popped element : %d\n" , Pop(&list));

    return 0;
}
