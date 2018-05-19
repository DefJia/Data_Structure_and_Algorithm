//
// Created by defjia on 18-5-18.
// 写一个算法判断给定的关键字序列k1, k2, …, kn是否为有序表中进行折半查找过程中可能出现的关键字比较序列。
//
#define LOCAL
#include <cstdlib>
#include <cstdio>
#define INF 99999999
int main(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
    freopen("../Create_use_cases/data.out.txt","w",stdout);
#endif
    int m;
    if(scanf("%d", &m) != 1) exit(1);
    while (m--) {
        int n, list[20], q;
        if (scanf("%d", &n) != 1) exit(1);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &q) != 1) exit(1);
            list[i] = q;
        }
        int max = INF, min = -INF, flag = 0;
        for (int i = 1; i < n - 1; i++) {
            if (list[i] == q || list[i] > max || list[i] < min) {
                flag = 1;
                break;
            }
            if ((list[i + 1] - list[i]) * (list[i] - q) > 0) {
                flag = 1;
                break;
            }
            if (list[i] > q) max = list[i];
            else min = list[i];
        }
        if (flag) printf("No.%d\n", m);
        else printf("Yes.%d\n", m);
    }
}