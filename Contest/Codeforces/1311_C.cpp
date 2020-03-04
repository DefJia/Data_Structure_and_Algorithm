#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 200000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

int main(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a;
    cin >> a;
    for(int i = 0; i < a; i++){
        int b, c;
        cin >> b >> c;
        char s[MAXSIZE];
        int l[MAXSIZE];
        cin >> s;
        int index = 0;
        int q;
        while (cin >> q){
            l[index++] = q;
            char ch = getchar();
            if(ch == '\n')
                break;
        }
        sort(l, l+c);

        int arr[26];
        for(int i = 0; i < 26; i++) arr[i] = 0;
        int num = 1;
        c--;
        for(int z = 0; z < b; z++){
            q = b-1-z;
            if(c >= 0) {
                while (l[c] == q + 1) {
                    num++;
                    c--;
                    if (c < 0) {
                        break;
                    }
                }
            }
            arr[(int)s[q]-97] += num;
        }


        for(int i = 0; i < 26; i++){
            cout << arr[i]  << ' ';
        }
        cout <<endl;
    }
    return 0;
}