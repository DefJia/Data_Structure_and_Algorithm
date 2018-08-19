//
// Created by defjia on 18-6-2.
//
/*
 *
 */
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <iostream>
#define ture true
#define mian main
#define falg flag
#define ll long long
#define MAX_SIZE 1000000
#define INF 1e9
using namespace std;
int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    ll n;
    ll m, arr[MAX_SIZE];
    scanf("%lld", &n);
    ll i = n;
    while (i--){
        scanf("%lld", &m);
        arr[n-i-1] = m;
    }
    ll max = 0, sum = 0;
    queue<pair<ll, ll>> tmp;
    ll cnt = 0, flag = 0;
    for(i = 0; i < n; i++){
        if(flag == 0 && arr[i] != 0) flag = 1;
        if(flag == 1){
            if(arr[i] != 0){
                if(arr[i] > 0){
                    tmp.push(make_pair(arr[i], 0));
                    sum += arr[i];
                    if(sum > max) max = sum;
                } else{
                    flag = 0;
                }
            }else{
                cnt++;
                tmp.back().second++;
                while (cnt > 3){
                    cnt -= tmp.front().second;
                    sum -= tmp.front().first;
                    tmp.pop();
                }
                if(sum > max) max = sum;
            }
        }
    }
    if(max < 0) max = 0;
    cout << max << endl;
}
