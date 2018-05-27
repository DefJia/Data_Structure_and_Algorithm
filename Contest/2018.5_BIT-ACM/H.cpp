//
// Created by defjia on 18-5-27.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72999
//
#include <bits/stdc++.h>
using namespace std;
int find(string s){
    int i = 0, j = 1, k = 0;
    while (i < s.size() && j < s.size() && k < s.size()){
        if(s[(i+k) % s.size()] == s[(j+k) % s.size()])
            k++;
        else if(s[(i+k) % s.size()] > s[(j+k) % s.size()]){
            i = i + k + 1;
            k = 0;
        } else{
            j = j + k + 1;
            k = 0;
        }
        if(i == j) j++;
    }
    return min(i, j) + 1;
}
int main(){
    string a;
    getline(cin, a);
    int res = find(a);
    cout << res << "\n";
    return 0;
}

