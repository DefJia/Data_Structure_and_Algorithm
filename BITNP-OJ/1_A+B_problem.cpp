//
// Created by defjia on 18-5-24.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    string a, b, c;
    while(getline(cin, a)){
        unsigned long index = a.find(" ");
        b = a.substr(0, index);
        a = a.substr(index+1, a.size()-index-1);
        stack<int> tmp;
        unsigned long ex = 0, i = a.size(), j = b.size(), q, p;
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
        printf("\n");
    }
    return 0;
}
