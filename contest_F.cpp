//
// Created by defjia on 18-4-28.
//
#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

long long int test(long long int t){
    if(t == 1) return 1;
    else if(t == 2) return 3;
    else if(t % 2 == 1) return 2 * t -1;
    //else if(t % 2 == 0) return test(t/2) + test(t/2 + 1) + (t - 2)/2 - 1;
    else if(t % 2 == 0) return test(t/2 + 1) * 2 -2;
}
int main(){
    int a;
    long long int tmp;
    if(scanf("%lld", &a) != 1) exit(0);
    while (a != EOF && a != '\n'&& a != ' '){
        printf("%lld\n", test(a));
        cin >> a;
    }
    return 0;
}