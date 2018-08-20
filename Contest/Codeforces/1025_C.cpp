//
// Created by defjia on 18-8-19.
// http://codeforces.com/contest/1025/problem/C
//
#include <bits/stdc++.h>
using namespace std;

int main(){
//#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    string a;
    cin >> a;
    char cur = 'a';
    int front = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != cur) {
            front++;
            cur = a[i];
        } else{
            break;
        }
    }
    cur = 'a';
    int end = 0;
    for(int i = a.length()-1; i >= 0; i--){
        if(a[i] != cur) {
            end++;
            cur = a[i];
        } else{
            break;
        }
    }
    int medium, max_ = 0;
    int i = front;
    while(i < a.length()-end){
        cur = 'a';
        medium = 0;
        for(int j = i; j < a.length()-end;){
            if(a[j] != cur) {
                medium++;
            } else{
                break;
            }
            cur = a[j++];
        }
        i += medium;
        max_ = max(max_, medium);
    }
    int res;
    if(a[0] == a[a.length()-1]){
        res = max(front, end);
        res = max(max_, res);
    } else{
        res = max(max_, front+end);
        if (res > a.length()) res /= 2;
    }
    cout << res << endl;
    return 0;
}
// Defjia loves Rebecca forever.