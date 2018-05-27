//
// Created by defjia on 18-4-28.
//
#include <iostream>
#include <cstdlib>
#include <string>
using  namespace std;
int main(){
    string a;
    getline(cin, a);
    int i,j, flag = 0, max_len = 0, len = 0;
    for(i = 0; i < a.size(); i++){
        switch (a[i]){
            case 'z':{
                len++;
                break;
            }
            case 'y': {
                break;
            }
            case '#':{
                len = 0;
            }
        }
        if (max_len < len) max_len = len;
    }
    cout << max_len;
}