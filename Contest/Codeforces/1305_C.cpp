#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
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
    int goal = 1, b;
    ago a, c;
    cin >> a >> b;
    ago x[MAXSIZE*2] = {0}, y[MAXSIZE] = {0};
    while (cin >> c){
        if (c > b) c = c % b + b;
        else c %= b;
        x[c]++;
        char ch = getchar();
        if(ch == '\n')
            break;
    }

    ago z = a, s;
    for (int i = 0; i < MAXSIZE*2; i++){
        if (x[i] > 1){
            cout << 0 << endl;
            return 0;
        }
        z -= x[i];
        s = z;
        for(int j = i+1; j < MAXSIZE*2 && s && x[i]; j++){
            y[abs(j-i)%b] += x[i] * x[j];
            s -= x[j];
        }
    }

    for (int i = 0; i < MAXSIZE; i++){
        for (int j = 0; j < y[i]; j++){
            goal = goal * i % b;
            if (goal == 0){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    cout << goal << endl;
    return 0;
}
