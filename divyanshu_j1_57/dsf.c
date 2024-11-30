#include<stdio.h>

void dfs(int[][4], int , int);
int visited[100];

int dir[][2] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};

int n = 4;

int main(){

    int graph[][4] = {
        {1,2,0,0},
        {3,0,4,0},
        {5,6,7,0},
        {8,9,0,0}
    };

    dfs(graph , 0 , 0);

    return 0;
}    
void dfs(int graph[][4] , int s , int e){

    if(visited[graph[s][e]] == -1){
        return;
    }
    
    if(graph[s][e] != 0){
        visited[graph[s][e]] = -1;
        printf("%d -> " , graph[s][e]);
    }

    for(int i = 0; i < 4; i++){
            int new_row = s + dir[i][0];
            int new_col = e + dir[i][1];

            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n){
                if(visited[graph[new_row][new_col]] != -1 && graph[new_row][new_col] >= 1){
                    dfs(graph , new_row , new_col);
                }
            }
        }
}