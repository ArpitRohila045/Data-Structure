#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct LinkedList{
    struct Node *Head;
    struct Node *Tail;
    int size;
};
struct LinkedList* create(){
    return (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
};

void Insert(struct LinkedList **list, int data){
    struct Node *temp = (struct Node*)calloc(1,sizeof(struct Node));
    temp->data = data;

    if((*list)->Head == NULL){
        (*list)->Head = temp;
        (*list)->Tail = temp;
        (*list)->size++;
        return;
    }
    (*list)->Tail->next = temp;
    (*list)->Tail = temp;
    (*list)->size++;
}

void Add_last(struct LinkedList **list, int data){
    struct Node *temp = (struct Node*)calloc(1,sizeof(struct Node));
    temp->data = data;

    if((*list)->Head == NULL){
        (*list)->Head = temp;
        (*list)->Tail = temp;
        (*list)->size++;
        return;
    }
    (*list)->Tail->next = temp;
    (*list)->Tail = temp;
    (*list)->size++;
}

void Add_first(struct LinkedList **list, int data){
    struct Node *temp = (struct Node*)calloc(1,sizeof(struct Node));
    temp->data = data;

    if((*list)->Head == NULL){
        (*list)->Head = temp;
        (*list)->Tail = temp;
        (*list)->size++;
        return;
    }
    temp->next = (*list)->Head;
    (*list)->Head = temp;
    (*list)->size++;
}

void Add_after(struct LinkedList **list,int position, int data){
    struct Node *temp = (struct Node*)calloc(1,sizeof(struct Node));
    temp->data = data;

    if(position > (*list)->size){
        printf("Invalid Input!\n");
        return;
    }
    struct Node *node = (*list)->Head;
    while(position-1){
        node = node->next;
        position--;
    }
    temp->next = node->next;
    node->next = temp;
    (*list)->size++;
}
void Display(struct LinkedList **list){
    struct Node *temp;
    temp = (*list)->Head;
    while(temp != NULL){
        printf("%d->" , temp->data);
        temp = temp->next;
    }
    printf("END\n");
    free(temp);
}

int main(){

    struct LinkedList *list = create();
    int choice = -1;
    int data;
    int position;
    while(choice){
        printf("======================================\n");

        printf("1 - Insert\n");
        printf("2 - Add_last\n");
        printf("3 - Add_first\n");
        printf("4 - Add_After\n");
        printf("5 - Display\n");
        printf("0 - Exit\n");
        printf("Enter the operation : ");
        scanf("%d", &choice);

        switch(choice){
        case(1):
            printf("Enter the Data value : ");
            scanf("%d" , &data);
            Insert(&list,data);
            break;
        case(2):
            printf("Enter the Data value : ");
            scanf("%d" , &data);
            Add_last(&list,data);
            break;
        case(3):
            printf("Enter the Data value : ");
            scanf("%d" , &data);
            Add_first(&list,data);
            break;
        case(4):
            printf("Enter the Data value : ");
            scanf("%d" , &data);
            printf("Enter the position : ");
            scanf("%d" , &position);
            Add_after(&list,position,data);
            break;
        case(5):
            Display(&list);
            break;
        case(0):
           return 0;
        }
    }
    return 0;
}
