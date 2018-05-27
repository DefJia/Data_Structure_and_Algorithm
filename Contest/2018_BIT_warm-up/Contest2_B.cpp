#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n, sum;
    cin >> n;
    while(n--){
        long long a, b;
        sum = 0;
        cin >> a;
        while (a != 0){
            if(a % 2 == 0) sum++;
            a = a / 2;
        }
        if(sum % 2 == 0) printf("0\n");
        else printf("1\n");
    }
}