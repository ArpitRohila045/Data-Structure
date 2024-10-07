#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>

// bool IsEmpty(void**);

struct Node{
    int data;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
};

bool IsEmpty(struct LinkedList **ll){
    return ((*ll)->head == NULL) ? true : false;
}

struct LinkedList* createLL(){
    struct LinkedList *ll = (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
    return ll;
}

void Enqueue(struct LinkedList **ll, int data){
    struct Node *temp = (struct Node*)calloc(1 , sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(IsEmpty(ll)){
        (*ll)->head = temp;
        (*ll)->tail = temp;
        (*ll)->size++;
        printf("Enqued\n");
        return;
    }

    (*ll)->tail->next = temp;
    (*ll)->tail = temp;
    (*ll)->size++;
    printf("Enqued\n");
}

int Dequeue(struct LinkedList **ll){
    if((*ll)->head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = (struct Node*)calloc(1 , sizeof(struct Node));
    temp = (*ll)->head;
    (*ll)->head = (*ll)->head->next;
    int data = temp->data;
    (*ll)->size--;
    free(temp);
    return data;
}


int size(struct LinkedList **ll){
    return (*ll)->size;
}
int main(){
    struct LinkedList *list = createLL();
    Enqueue(&list , 59);
    Enqueue(&list , 69);
    Enqueue(&list , 5);
    Enqueue(&list , 10);
    Enqueue(&list , 80);
    Enqueue(&list , 44);
    Enqueue(&list , 10);

    printf("%d\n" , Dequeue(&list));
    printf("%d\n" , Dequeue(&list));
    return 0;

}    

