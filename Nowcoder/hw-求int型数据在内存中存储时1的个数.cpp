#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
    int a;
    cin >> a;
    int n = 0;
    while(a > 1){
        if (a%2 == 1) n++;
        a = a / 2;
    }
    n++;
    cout << n << endl;
    return 0;
}
