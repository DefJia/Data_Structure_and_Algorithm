//
// Created by defjia on 18-8-15.
// https://www.luogu.org/recordnew/show/9723519
//
#include <bits/stdc++.h>
using namespace std;

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int res, budget, balance = 0, bank = 0, count = 1;
    while (cin >> budget){
        if (budget > balance + 300){
            res = - count;
            break;
        } else{
            balance += 300 - budget;
            while (balance >= 100){
                balance -= 100;
                bank += 100;
            }
        }
        count++;
    }
    if (count == 13) res = (int)(balance + 1.2 * bank);
    cout << res;
    return  0;
}
