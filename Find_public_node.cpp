//
// Created by defjia on 18-4-15.
//
#include <stdio.h>
#include <cstdlib>
#define  MAXSIZE 1000
int main(){
    int i, j, n, x, y;
    int t[MAXSIZE], a[MAXSIZE], b[MAXSIZE];
    if(!scanf("%d\n", &n))exit(1);
    for(i = 0; i < n; i++){
        if(!scanf("%d", &j))exit(2);
        t[i] = j;
    }
    if(!(scanf("%d %d", &x, &y))) exit(4);
    if(t[x-1] == 0){printf("ERROR: T[%d] is NULL\n", x); return 0;}
    if(t[y-1] == 0){printf("ERROR: T[%d] is NULL\n", y); return 0;}
    i = 0; while (x >= 1) {a[i++] = x; x = x/2;}
    j = 0; while (y >= 1) {b[j++] = y; y = y/2;}
    n = 1;
    while (n<=j && n<=i && a[i-n] == b[j-n]) {n++;}
    printf("%d %d\n", a[i+1-n], t[a[i+1-n]-1]);
    return  0;
}
