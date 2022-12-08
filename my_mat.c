#include <stdio.h>
#define N 10

int dfs(int mat[N][N] , int visited[N] , int start, int end);

/*
create a matrix from user input
*/
void createmat (int mat[N][N]){  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d" , &mat[i][j]); // mat[i][j] = input
        }            
    }    
}

/*
The function get a matrix that represent a graph and two ints that represents starf and end position.
The function print "True" if there is a path in the graph or "False" if not.
*/
void path(int mat[N][N] , int i , int j){ 
    if(i == j || i < 0 || j < 0 || i >= N || j >= N){ // if the start=end or the start/end are out of bounds - prinf "False"
        printf("False\n");
    }
    else{
        int visited[N]; // create a array that represent the node that i already chacked 
        for (int x = 0; x < N; x++) // initialization the array to 0 for each index;
        {
            visited[x] = 0;
        }
        int ans = dfs(mat , visited , i , j); // send the parameters to the dfs function 
        if (ans == 1) // if there is a path
        {
            printf("True\n");
        }
        else{
            printf("False\n");
        } 
    }   
}
 
/*
The function get a matrix that represent a graph and two ints that represents starf and end position.
The function print return 1 if there is a path in the graph or 0 if not.
this function use the the DFS algorithm.
*/
int dfs(int mat[N][N] , int visited[N] , int start, int end)
{
    if (start == end) // if start equals to end - it's mean i have a path
        return 1;
    visited[start] = 1; // else - mark i as visited
    for (int x = 0; x < N; x++) //for each node 
    {
        if (!visited[x] && mat[start][x] != 0) // if not visited and i have a path to him
            if (dfs( mat , visited , x, end) == 1)  //serch if i get to end
                return 1;
        
    }
    return 0;
}
/*
A function that copy a matrix to other martix
*/
void copy(int mat[N][N] , int copym [N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copym[i][j] = mat[i][j];
        }
    }
}

/*
The function use the Floyd–Warshall algorithm for finding the shortest path in a graph.
The function get a matrix and 2 index of start and end , and print the shortest path from start -> end.
If there is not a path - print -1..
*/
void shortpath (int mat[N][N] , int start , int end){
        if(start == end || start < 0 || end < 0 || start >= N || end >= N){ // if the start=end or the start/end are out of bounds - prinf -1 
        int false_input = -1;
        printf("%d\n" , false_input);
    }
    else{
        int graph[N][N] = {0};
        copy(mat , graph); // to not overide on the matrix
        for (int k = 0; k < N; k++){ 
            for (int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(graph[i][j] == 0 && (graph[i][k] == 0 || graph[k][j] == 0)){ //check if there is a path 
                        //nothing
                    }
                    else if (graph[i][j] != 0 && (graph[i][k] == 0 || graph[k][j] == 0))
                    {
                        //nothing                
                    }
                    else if (graph[i][j] == 0 && graph[i][k] != 0 && graph[k][j] != 0)
                    {
                    graph[i][j]= graph[i][k] + graph[k][j];
                    }
                    else{
                        if ( graph[i][j] > graph[i][k] + graph[k][j]) // take the minimum path between graph[i][j] , graph[i][k] + graph[k][j]
                        {
                            graph[i][j]= graph[i][k] + graph[k][j];
                        }
                    }
                }
            }
        }
        if(graph[start][end] == 0) // if there is not path
        {
        int false_input = -1;
        printf("%d\n" , false_input);
        }
        else{
            printf("%d\n" , graph[start][end]);
        }
    }
}