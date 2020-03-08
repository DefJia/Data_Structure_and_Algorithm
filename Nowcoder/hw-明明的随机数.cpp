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
    int a, b, c[MAXSIZE];
    while(cin >> a){
        memset(c, 0, sizeof(c));
        for (int i = 0; i < a; i++){
            cin >> b;
            c[b]++;
        }
        for(int i = 0; i < MAXSIZE; i++){
            if(c[i] > 0)
                cout << i << endl;
        }
    }
    return 0;
}
