#include <stdio.h>
#include "my_mat.h"
#define N 10

int main(){
    char scan = 'a'; 
    int mat [N][N] = {0};
    do
    {
        scan = 'a'; 
        scanf("%c" , &scan);
        if(scan == 'A'){
            createmat(mat);
        }
        if(scan == 'B'){
            int i = 0;
            int j = 0;
            scanf("%d" , &i);
            scanf("%d" , &j);
            path(mat , i , j);
        }
        if(scan == 'C'){
            int i=0;
            int j=0;
            scanf("%d" , &i);
            scanf("%d" , &j);
            shortpath(mat , i , j);
        }

    } while (scan != 'D');
}
