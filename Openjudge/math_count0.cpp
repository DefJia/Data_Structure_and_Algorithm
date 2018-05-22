//
// Created by defjia on 18-5-22.
//
#include <cstdlib>
#include <cstdio>
#include <math.h>
#define MAXSIZE 10000
int main(){
    int max = MAXSIZE, time = 0;
    while (max / 5 > 1) {max /= 5; time++;}
    int a, b, count = 0, aa, bb;
    scanf("%d %d", &a, &b);
    while (time){
        aa = (a - 1) / pow(5, time);
        bb = b / pow(5, time);
        count += bb - aa;
        time--;
    }
    int count5  = count;
    max = MAXSIZE;
    int time2 = 0;
    while (max / 2 > 1) {max /= 2; time2++;}
    count = 0, aa, bb;
    while (time2){
        aa = (a - 1) / pow(2, time2);
        bb = b / pow(2, time2);
        count += bb - aa;
        time2--;
    }
    count = count > count5? count5: count;
    printf("%d\n", count);
}
