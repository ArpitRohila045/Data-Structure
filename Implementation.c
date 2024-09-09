#include <stdio.h>

int *arr;
int top = -1 , size;

int* createStack(int n){
    size = n;
    return (int*)calloc(sizeof(int) , n);
}

void push(int *stack, int data){

    if(top == size-1){
        printf("Stack overflow!");
        exit(0);
    }

    stack[++top] = data;
}

int pop(int *stack){

    if(top == -1){
        printf("Stack underflow!");
        exit(0);
    }

    return stack[top--];
}

int main(){
    int *stack = createStack(5);
    push(stack , 35);
    push(stack , 45);
    push(stack , 55);
    push(stack , 65);
    push(stack , 55);
    push(stack , 55);

    printf("%d\n" , pop(stack));
    printf("%d\n" , pop(stack));

}
