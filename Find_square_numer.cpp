//
// Created by defjia on 18-5-15.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=70871
//
#include <cstdlib>
#include <stdio.h>
#include <math.h>
int is_square(int a){
    int tmp = (int)sqrt((long double)a);
    if(tmp * tmp == a) return 1;
    else return 0;
}
int main(){
    int m, n;
    int i, j;
    int q = 0, p = 0;
    int sum = 0;
    if(scanf("%d,%d", &m, &n) != 2) exit(1);
    for(i = 0; i < n - m + 1; i++){
        if(is_square(m + i)) {
            q = 1;
            break;
        }
    }
    for(j = 0; j < n - m + 1; j++) {
        if(is_square(n - j)) {
            p = 1;
            break;
        }
    }
    if(p*q != 0) {
        if (m + i == n - j) {sum = (m + i) * (m + i);}
        else {
            for (q = (int) sqrt((long double) m + i); q <= (int) sqrt((long double) n - j); q++) sum += q * q;
        }
    }
    // cout << sum << "\n";
    printf("%d\n", sum);
}

