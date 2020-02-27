//
// Created by defjia on 18-8-23.
//
//
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
#define falg flag
#define ture true
typedef long long ago;
typedef double kill_;

int main(){
//#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    ago x, n, res;
    cin >> x >> n;
    if (x + n <= 6) res = 250 * n;
    else{
        n -= 8 - x;
        ago tmp = n % 7;
        if (tmp == 6) tmp--;
        if (x == 7) x--;
        res = 250 * (tmp + 6 - x);
        tmp = n / 7;
        res += 250 * tmp * 5;
    }
    cout << res << endl;
    return 0;
}
// Defjia loves Rebecca forever.