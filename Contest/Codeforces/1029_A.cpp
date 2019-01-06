//
// Created by defjia on 18-8-24.
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
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a, b, i;
    cin >> a >> b;
    string c;
    for(i = 0; i < c.size(); i++){
        if(c[i] == c[c.size()-1]){
            break;
        }
    }
    int flag = 0, j = c.size()-1;
    while(i != -1 and falg == 0){
        if(c[i] != c[j])
            flag = 1;
    }
    if(!flag){
        for(int i = 0; i < b; i++)
            cout << c;
    }else{

    }
    return 0;
}
// Defjia loves Rebecca forever.