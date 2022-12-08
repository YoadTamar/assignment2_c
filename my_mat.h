#include <stdio.h>
#define N 10

void createmat (int mat[N][N]); //fun n.1
void path(int mat[N][N] , int i , int j); //fun n.2
int dfs(int mat[N][N] , int visited[N] , int start, int end);
void copy(int mat[N][N] , int copym [N][N]);
void shortpath (int mat[N][N] , int start , int end); // fun n.3
