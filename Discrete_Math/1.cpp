#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 3000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
//#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int n, tmp, sum = 0, flag = 1;
    if(scanf("%d", &n) != 1) exit(1);
    int arr[MAXSIZE] = {0};
    for(int i = 0; i < n; i++){
        if(scanf("%d", &tmp) != 1) exit(1);
        arr[i] = tmp;
        sum += tmp;
    }
    while(n-- and flag){
        sort(arr, arr+n+1, greater<int>());
        int cur = arr[0];
        if (cur > n){
            flag = 0;
            break;
        }
        for(int i = 0; i < cur; i++){
            arr[i+1]--;
            if(arr[i+1] < 0){
                flag = 0;
                break;
            }
        }
        swap(arr[0], arr[n]);
    }
    if(sum % 2 == 0 and flag == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}