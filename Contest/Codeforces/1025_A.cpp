//
// Created by defjia on 18-8-19.
// http://codeforces.com/contest/1025/problem/A
//
#include <bits/stdc++.h>
#define MAX 26
using namespace std;

int main(){
//#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int n, flag = 0;
    string str;
    cin >> n;
    cin >> str;
    int arr[MAX];
    // memset(arr, 0, MAX);
    for (int i = 0; i < MAX; i++) arr[i] = 0;
    for(int i = 0; i < str.length(); i++){
        if(arr[str[i]-'a'] == 0) arr[str[i]-'a']++;
        else{
            flag = 1;
            break;
        }
    }
    if(n == 1) flag = 1;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return  0;
}
// Defjia loves Rebecca forever.