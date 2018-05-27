//
// Created by defjia on 18-5-24.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72997
// 2
// abba
// abbaaa
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string a;
        getline(cin, a);
        int m = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 'a') m++;
            else m--;
        }
        if(m) cout << "no\n";
        else cout << "yes\n";
    }
}
