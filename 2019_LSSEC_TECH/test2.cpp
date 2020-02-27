#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
//#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    ago a, b, p, r;
    cin >> a >> b >> p;
    r = (a * b) % p;
    cout << r;
    return 0;
}
