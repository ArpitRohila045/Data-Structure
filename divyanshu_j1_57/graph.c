#include<stdio.h>

int main(){
    int n = 4;
    int graph[][4] = {
        {1,1,0,0},
        {1,0,1,0},
        {1,1,1,0},
        {1,1,0,0}
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }

    int q[2][100];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 100; j++){
            q[i][j] = 0;
        }
    }

    int start = -1;
    int end = 0;

    int visited[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = -1;

    int dir[][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    while(end >= start){
        int row = q[++start][0];
        int col = q[start][1];

        for(int i = 0; i < 4; i++){
            int new_row = row + dir[i][0];
            int new_col = col + dir[i][1];

            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n){
                if(visited[new_row][new_col] != -1 && graph[new_row][new_col] == 1){
                    q[0][end] = new_row;
                    q[1][end++] = new_col;
                    visited[new_row][new_col] = -1;
                }
            }
        }
        printf("%d -> %d - > ", row , col);
    }
    // for(int i = 0; i < n; i++){
    //     printf("%d :--> ", i);
    //     for(int j = 0; j < n; j++){
    //         if(graph[i][j] == 1){
    //             printf("%d -> " , j);
    //         }
    //     }
    //     printf("END\n");
    // }
}