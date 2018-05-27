//
// Created by defjia on 18-4-28.
//
#include <stdio.h>
#include <cstdlib>
#define MAXSIZE 100000

int main(){

    long long int cur = 0, t;
    if(scanf("%lld", &t) != 1) exit(0);
    while (t--) {
        long long int arr[MAXSIZE][2];
        long long int n, i, j, t;
        if (scanf("%lld", &n) != 1) exit(0);
        i = n;
        while (n--) {
            if (scanf("%lld", &j) != 1) exit(0);
            arr[i - n][0] = j;
        }
        memset(arr[1], -1 ,MAXSIZE);
        sum = -1;
        while (sum == 0) {
            for (i = 0; i < n; i++) {
                if()
            }
            sum++;
        }
    }
}
