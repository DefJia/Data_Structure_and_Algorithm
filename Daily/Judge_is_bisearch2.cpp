//
// Created by defjia on 18-5-18.
// the same as Judge_is_bisearch.cpp
//
#define LOCAL
#include <cstdlib>
#include <cstdio>
#define INF 999999
int main(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
    freopen("../Create_use_cases/data.out2.txt","w",stdout);
#endif
    int m;
    if(scanf("%d", &m) != 1) exit(1);
    while(m--){
        int n, list[20], q, i;
        if(scanf("%d", &n) != 1) exit(1);
        for(i = 0; i < n; i++){
            if (scanf("%d", &q) != 1) exit(1);
            list[i] = q;
        }
        int max = INF, min = -INF;

        for(i = 1; i < n; i++){
            if(list[i] < min || list[i] > max) break;
            if(list[i] == q && i != n-1) break;
            if(list[i] > q) max = list[i];
            else min = list[i];
        }
        if(i == n) printf("Yes.%d\n", m);
        else printf("No.%d\n", m);
    }
}

