//
// Created by defjia on 18-6-2.
//
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <iostream>
#define ture true
#define mian main
#define falg flag
#define ll long long
#define MAX_SIZE 100000
using namespace std;
int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    ll n, m, arr[MAX_SIZE], brr[MAX_SIZE], a, ai = 0, bi = 0, divide;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a);
        divide = a / m;
        if (a >= 0) arr[ai++] = divide;
        else brr[bi++] = divide;
    }
    ll sum_a = 0, sum_b = 0;
    for(int i = 0; i < ai; i++){

    }

}
