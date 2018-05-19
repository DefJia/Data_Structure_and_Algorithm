//
// Created by defjia on 18-5-14.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68470
//
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#define MAXSIZE 66
int main(){
    int n, i, tmp[MAXSIZE];
    memset(tmp, 0, sizeof(tmp));
    if(scanf("%d", &n) != 1) exit(1);
    while(n--){
        if(scanf("%d", &i) != 1) exit(1);
        tmp[i] += 1;
    }
    for(i = 0; i < MAXSIZE; i++){
        if(tmp[i] != 0) printf("%d:%d\n", i, tmp[i]);
    }
}

