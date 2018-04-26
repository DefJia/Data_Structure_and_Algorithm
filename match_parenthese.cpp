//
// Created by defjia on 18-4-15.
//
#include <stack>
#include <string>
#include <iostream>
using namespace std;
int main(){
    stack<char> a;
    string c;
    int flag = 0;
    cin >> c;
    for(unsigned int i = 0; i < c.size(); i++){
        switch (c[i]){
            case '[':
                a.push('[');
                break;
            case ']':
                if(a.empty() || a.top()!='['){
                    cout<<"Match false!\n";
                    flag = 1;
                    break;
                }
                a.pop();
                break;
            case '(':
                a.push('(');
                break;
            case ')':
                if(a.empty()||a.top()!='('){
                    cout<<"Match false!\n";
                    flag = 1;
                    break;
                }
                a.pop();
                break;
            default:
                break;
        }
        if (flag != 0) return 0;
    }
    if(!a.empty()) {cout << "Match false!\n";
        return 0;}
    cout << "Match succeed!\n";
    return 0;
}