#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a[MAXSIZE][MAXSIZE];
    int i, j, t, k, n, cur;
    if(scanf("%d", &n) != 1) exit(1);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            if(scanf("%d", &t) != 1) exit(1);
            a[i][j] = t;
        }
    // Construction
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++){
                if(a[i][k] and a[k][j])
                    a[i][j] = 1;
            }
    // Integration
    if (n < 3) {
        cout << "1" << endl;
        return 0;}
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            if(a[i][j] == 0 and a[j][i] == 0){
                cout << "3" << endl;
                return 0;
            }
            if(a[i][j] + a[j][i] == 1){
                cout << "2" << endl;
                return 0;
            }
        }
    cout << "1" << endl;
    return 0;
}