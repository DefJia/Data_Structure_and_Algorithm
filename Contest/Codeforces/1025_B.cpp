//
// Created by defjia on 18-8-19.
// http://codeforces.com/contest/1025/problem/B
//
#include <bits/stdc++.h>
#define MAX 150000
#define GREAT 20000
using namespace std;

void gcd(int * arr, int a, int b){
    int tmp[10000], count = -1;
    int cur = 0;
    while(a % 2 == 0){
        a = a / 2;
        count = 0;
        cur = 2;
        tmp[count] = 2;
    }
    for (int i = 3; a >= i;){
        if(a % i == 0){
            a /= i;
            if(cur != i){
                tmp[++count] = i;
            }
            cur = i;
        } else{
            i += 2;
        }
    }
    if(count == -1) tmp[++count] = a;
    int tmp2[10000], count2 = -1;
    cur = -1;
    while(b % 2 == 0){
        b = b / 2;
        count2 = 0;
        tmp2[count2] = 2;
    }
    for (int i = 3; b >= i;) {
        if (b % i == 0) {
            b /= i;
            if(cur != i){
                tmp2[++count2] = i;
            }
            cur = i;
        } else {
            i += 2;
        }
    }
    if(count2 == -1) tmp2[++count2] = b;
    while(count + count2 != -2){
        if(count >= 0 and count2 >= 0){
            if(tmp[count] > tmp2[count2]){
                arr[tmp[count]]++;
                count--;
                if(tmp[count] == tmp2[count2])
                    count2--;
            }else {
                arr[tmp2[count2]]++;
                count2--;
                if(tmp[count] == tmp2[count2])
                    count--;
            }
        } else{
            if (count2 >= 0){
                while(count2 != -1){
                    arr[tmp2[count2]]++;
                    count2--;
                }
            }else{
                while(count != -1){
                    arr[tmp[count]]++;
                    count--;
                }
            }
        }
    }
    int aa = 0;
}

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a, arr[GREAT];
    memset(arr, 0, sizeof(arr));
    cin >> a;
    int b, c, aa = a;
    while (a--){
        cin >> b >> c;
        gcd(arr, b, c);
    }
    int flag = 0;
    for(int i = 1; i < GREAT; i++){
        if(arr[i] == aa){
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
    return  0;
}
// Defjia loves Rebecca forever.