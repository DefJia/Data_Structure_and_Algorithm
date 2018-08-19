//
// Created by defjia on 18-6-2.
//
#include <bits/stdc++.h>
#include <zconf.h>
using namespace std;
class A{
public:
    A(): a(0){
        cout << a << endl;
    }
    ~A(){
        cout << a << endl;
    }
    int a;
};
A a;
int main(){
    if(fork() == 1){
        ++a.a;
    }
    return 0;
}