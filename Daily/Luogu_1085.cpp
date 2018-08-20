//
// Created by defjia on 18-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
// #define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a, b, flag = 7, res = 0, i = 1;
    while(cin >> a >> b){
        if (a + b >= 8){
            if (a + b > flag){
                flag = a + b;
                res = i;
            }
        }
        i++;
    }
    cout << res;
    return  0;
}
