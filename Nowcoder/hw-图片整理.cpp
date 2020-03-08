#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAXSIZE 1024
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
    cin >> a;
    int b[a.length()];
    for (int i = 0; i < a.length(); i++)
        b[i] = (int)a[i];
    sort(b, b+a.length());
    for (int i = 0; i < a.length(); i++)
        cout << (char)b[i];
    return 0;
}