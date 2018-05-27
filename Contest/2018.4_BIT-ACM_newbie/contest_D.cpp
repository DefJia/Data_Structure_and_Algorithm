//
// Created by defjia on 18-4-28.
//
#include <stdio.h>
#include <cstdlib>
#define MAXSIZE 100000

int main(){
    long long int n, t, i, sum= 0;
    int cur, cx  = 1, cy = 1, flag = 0, tx, ty, last_direction = 2, cur_direction;
    long long int a[2][MAXSIZE];
    if(scanf("%lld", &n) != 1) exit(0);
    for(i = 0; i < n; i++) {
        if (scanf("%lld", &t) != 1) exit(0);
        a[0][i] = t;
    }
    for(i = 0; i < n; i++) {
        if (scanf("%lld", &t) != 1) exit(0);
        a[1][i] = t;
    }
    sum = a[0][0];
    //Construct
    //flag: 0 -> min, 1->max;
    //cur_direction: 0, up; 1, down; 2, right;
    while (cx != n || cy != 2){
        if(cy == 1) tx = a[1][cx-1];
        else tx = a[0][cx-1];
        ty = a[cy-1][cx];
        if(last_direction < 2 ) cur_direction = 2;
        else if(cx == n) cur_direction = 1;
        else if(flag == 0)cur_direction = ty <= tx? 2 : 2-cy;
        else cur_direction = ty >= tx? 2 : 2-cy;
        switch (cur_direction){
            case 0:{
                cy -= 1;
                sum += tx;
                flag = 1;
                break;
            }
            case 1:{
                cy += 1;
                sum += tx;
                flag = 1;
                break;
            }
            case 2:{
                cx += 1;
                sum += ty;
                flag = 0;
                break;
            }
        }
        last_direction = cur_direction;
    }
    // sum += a[1][n-1];
    printf("%lld", sum);
}
