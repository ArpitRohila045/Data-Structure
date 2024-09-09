#include <stdio.h>

int search(int arr[][4] , int n){
    int row = 0, col = 3;
    while(row <= 3 && col >= 0){
        if(arr[row][col] == n){
            return 1;
        }

        if(n > arr[row][col]){
            row++;
        }else{
            col--;
        }
    }
    return 0;
}

int main(){

    int n;
    int arr[][4] = {
        {10, 20 , 30 , 40},
        {15, 25 , 34 , 41},
        {27, 29 , 35 , 45},
        {32, 33 , 38 , 49}
    };
    scanf("Enter a number %d" , &n);
    if(search(arr , n)){
        printf("%d is found" , n);
    }else{
        printf("Not found");
    }

}
