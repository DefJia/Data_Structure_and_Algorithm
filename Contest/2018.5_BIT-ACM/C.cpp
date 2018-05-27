//
// Created by defjia on 18-5-27.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72993
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if(scanf("%d", &n) != 1) exit(1);
    while (n--){
        int a,b,c;
        if(scanf("%d %d %d", &a, &b, &c) != 3) exit(1);
        if(a*b*c == 1) printf("czWin!\n");
        else printf("v5zsq!\n");
    }
}
