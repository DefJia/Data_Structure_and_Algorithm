//
// Created by defjia on 18-8-23.
// https://www.luogu.org/problemnew/show/P1423
//
#include <bits/stdc++.h>
using namespace std;

int main(){
// #define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    double a = 2.0;
    float b;
    scanf("%f", &b);
    int cnt = 1;
    while(b > a){
        b -= a;
        cnt++;
        a = a * 0.98;
    }
    cout << cnt;
    return 0;
}