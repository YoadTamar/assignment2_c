#include <stdio.h>
#include "my_mat.h"
#define N 10

int main(){
    char scan = 'a'; 
    int mat [N][N];
    do
    {
        scanf("%c" , &scan);
        if(scan == 'A'){
            createmat(mat);
        }
        if(scan == 'B'){
            int i;
            int j;
            scanf("%d" , &i);
            scanf("%d" , &j);
            path(mat , i , j);
        }
        if(scan == 'C'){
            int i;
            int j;
            scanf("%d" , &i);
            scanf("%d" , &j);
            shortpath(mat , i , j);
        }

    } while (scan != 'D');
}
