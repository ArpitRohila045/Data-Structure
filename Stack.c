#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int Top;
    unsigned int Capacity;
    int *arr;
};

struct Stack* Create_stack(){
    struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
    printf("Enter the Capacity of stack : ");
    scanf("%d" , &st->Capacity);
    st->Top = -1;
    st->arr = (int*)calloc(st->Capacity , sizeof(int));

    return st;
}

int isFull(struct Stack* st){
     return st->Top == st->Capacity ? 1 : 0;
}

int isEmpty(struct Stack* st){
    return st->Top == -1 ? 1 : 0;
}

void push(struct Stack* st){
    if(!isFull(st)){
        printf("Enter the Top of the Stack : ");
        scanf("%d" , &st->arr[++st->Top]);
        return;
    }
    printf("stack Overflow !\n");
    exit(0);
}

int pop(struct Stack* st){
    if(!isEmpty(st)){
        printf("Top of the stack : %d\n" ,st->arr[st->Top--]);
        return st->arr[st->Top];
    }
    printf("Stack is Empty!\n");
    return __INT32_MAX__;
}

void Display(struct Stack* st){

    printf("==========Stack Is========\n");
    int temp = st->Top;
    while(temp >= 0){
        printf("-> %d \n" , st->arr[temp--]);
    }
}

int main(){
    struct Stack* st = Create_stack();

    push(st);
    push(st);
    push(st);
    push(st);

    pop(st);
    pop(st);

    Display(st);

    return 0;
}