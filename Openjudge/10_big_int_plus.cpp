//
// Created by defjia on 18-5-22.
// http://noi.openjudge.cn/ch0106/10/
//
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    stack<int> tmp;
    int ex = 0, i = a.size(), j = b.size(), q, p;
    while(ex != 0 || i > 0 || j > 0){
        q = 0; p = 0;
        if(i > 0){
            q = a[i-1] - '0';
            i--;
        }
        if(j > 0){
            p = b[j-1] - '0';
            j--;
        }
        if(q + p + ex >= 10){
            tmp.push(q + p + ex - 10);
            ex = 1;
        } else{
            tmp.push(q + p + ex);
            ex = 0;
        }
    }
    while (!tmp.empty() && tmp.top() == 0) tmp.pop();
    if(tmp.empty()) printf("0");
    while (!tmp.empty()){
        printf("%d", tmp.top());
        tmp.pop();
    }
    return 0;
}