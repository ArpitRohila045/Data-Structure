#include <stdio.h>
#include <stdlib.h>

int main(){

    char arr[] = "(()()(()))()";
    char *ptr = arr;
    int left = 0;
    int right = 0;
    int max_len = 0;

    while(*ptr != '\n'){
        char ch = *ptr;
        if(ch == '('){
            left++;
        }else {
            if(left == right){
                int max = left * 2;
                max_len = max_len > max ? max_len : max;
            }else{
                right++;
            }
        }
        ptr++;
    }

    printf("%d " , max_len);

    return 0;
}
