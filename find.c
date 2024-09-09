#include <stdio.h>

int find(int arr[][3]){

    int row = 0, col = 2;
    int sum = 0;
    while(row <= 3 && col >= 0){

        if(arr[row][col]){
            col--;
            sum++;
        }else{
            row++;
        }
    }
    return sum;
}

int main(){

    int size;
    int arr[][3] = {
        {0 , 1, 1},
        {0 , 0, 1},
        {1 , 1, 1},
        {0 , 0, 0}
    };
    printf("%d" , find(arr));

    return 0;
}
