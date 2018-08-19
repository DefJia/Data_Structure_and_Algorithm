//
// Created by defjia on 18-8-14.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    double b;
    cin >> a;
    if (a <= 150){
        b = 0.4463 * a;
    } else if (a <= 400){
        b = 0.4463 * 150 + 0.4663 * (a - 150);
    } else{
        b = 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (a - 400);
    }
    printf("%.1f\n", b);
    return  0;
}
