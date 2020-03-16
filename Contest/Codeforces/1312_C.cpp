// Time limit exceeded on test 5
#include <iostream>
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
    int a, l, k;
    ago t;
    cin >> a;
    for(int q = 0; q < a; q++){
        cin >> l >> k;
        int ll = 0;
        ago v[l]= {0};;
        ago max = 0;
        int nn = 0;
        for(int p = 0; p < l; p++){
            cin >> t;
            if (t > max) max = t;
            if(t) v[nn++] = t;
            else ll++;
        }
        l -= ll;
        // construct
        ago hash[60]= {0};;
        int tmp = 1, n = 0;
        while(tmp <= max){
            hash[n++] = tmp;
            tmp *= k;
        }
        int res[n--]= {0};;
        string flag = "YES";
        for(int p = 0; p < l; p++){
            for (int m = n; m >= 0; m--){
                if(v[p] >= hash[m]){
                    v[p] -= hash[m];
                    res[m]++;
                }
            }
            if (v[p]){
                flag = "NO";
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (res[i] > 1){
                flag = "NO";
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}