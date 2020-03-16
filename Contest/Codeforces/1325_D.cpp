#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAXSIZE 1000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    ago _xor, sum;
    cin >> _xor >> sum;
    if (_xor > sum or (sum+_xor)%2) cout << -1 << endl;
    else if(_xor == sum){
        if(_xor) cout << 1 << endl << _xor << endl;
        else cout << 0 << endl;
    } else{
        ago minus = sum - _xor;
        ago q = (ago) (minus / 2);
        if ((q ^ _xor) == (q + _xor)) cout << 2 << endl << q << ' ' << q+_xor << endl;
        else cout << 3 << endl << q << ' ' << q << ' ' << _xor << endl;
    }
    return 0;
}
