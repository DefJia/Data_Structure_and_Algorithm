//
// Created by defjia on 18-8-19.
// http://codeforces.com/contest/1036/problem/C
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int nn;
    cin >> nn;
    ll a, b, c, x, n, t,d;
    for(int i = 0; i < nn; i++){
        cin >> a>>b>>c;
        x = max(a,b);
        n = min(a,b);
        t = n;
        d = t;
        if ((x - n)%2 == 0){
            d += x-n;
            t += x-n;
        } else{
            d += x-n-1;
            t += x-n;
        }
        // minimal steps
        if(t > c) cout << -1 << endl;
        else{
            ll diff = c - t;
            d += ((ll)diff/2)*2;
            t += ((ll)diff/2)*2;
            if(diff % 2 == 0) cout << d << endl;
            else{
                if(t-d > 0) cout << d+1 << endl;
                else cout << d-1 << endl;
            }
        }
    }
    return 0;
}
// Defjia loves Rebecca forever.