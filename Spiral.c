#include<stdio.h>

int main(){

    int row = 0, l_col = 3, l_row = 3 , col = 0;
    int arr[][4] = {
        {10, 20 , 30 , 40},
        {15, 25 , 34 , 41},
        {27, 29 , 35 , 45},
        {32, 33 , 38 , 49}
    };

    int pre = arr[0][0];
    for(int i = col; i < l_col; i++){
        int current = arr[row][i+1];
        arr[row][i+1] = pre;
        pre = current;
    }
    row++;

    for(int i = row; i <= l_row; i++){
        int current = arr[i][l_col];
        arr[i][l_col] = pre;
        pre = current;
    }
    l_col--;

    for(int i = l_col; i > col; i--){
        int current = arr[l_row][i];
        arr[l_row][i] = pre;
        pre = current;
    }
    l_row--;

     for(int i = l_row; i >= row; i--){
        int current = arr[col][i];
        arr[row][i] = pre;
        pre = current;
    }
    col++;

     for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d " ,arr[i][j]);
        }
        printf("\n");
     }
}
