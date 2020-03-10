#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100000
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
    string a;
    getline(cin, a);
    char b, c;
    cin >> b;
    if(48 <= (int)b && (int)b <= 57) c = b;
    else if (65 <= (int)b && (int)b <= 90) c = (char)((int)b + 32);
    else c = (char)((int)b - 32);
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if (a[i] == b || a[i] == c)
            cnt++;
    }
    cout << cnt;
    return 0;
}
