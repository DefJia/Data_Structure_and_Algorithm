#include <stdio.h>
#include <cstdlib>

typedef struct
{
    int x, y;
}point;

point stack[4951];
//the worst situation
int top = -1;
int map[102][102] = {0};
//with boundary
void forward(int a, int b)
{
    stack[++top].x = a;
    stack[top].y = b;
    map[a][b] = -1;
}
void backward(int a, int b){

}


int main()
{
    int m, n, i, j;
    if (scanf("%d%d",&m, &n) != 2){exit(1);}
    for (i = 0; i <= m + 1; i++){
        for (j = 0; j <= n + 1; j++){
            if (i * j > 0 && i <= m && j <= n){
                if (scanf("%d", &map[i][j]) != 1){exit(1);}
            } else{
                map[i][j] = 2;
            }
        }
    }
    //create map
    if (map[1][1] == 1)
    {
        printf("There is no solution!\n");
        return 0;
    }
    forward(1,1);
    while (1)
    {   
        if (top == -1)
        {
            printf("There is no solution!\n");
            return 0;
        }
        i = stack[top].x;
        j = stack[top].y;
        //printf("<%d,%d> ",i,j);
        if (m == i&&n == j){
            break;
        }
        if(map[i+1][j] == 0)
        {
            forward(i+1, j);
            continue;
        }
        else if (map[i][j+1] == 0)
        {
            forward(i, j+1);
            continue;
        }
        else if (map[i-1][j] == 0)
        {
            forward(i-1, j);
            continue;
        }
        else if (map[i][j-1] == 0)
        {
            forward(i, j-1);
            continue;
        }
        top--;
    }
    for (i = 0; i <= top; i++){
        printf("<%d,%d> ",stack[i].x, stack[i].y);
    }
    printf("\n");
    return 0;
}