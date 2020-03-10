#include <bits/stdc++.h>
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
    string data[MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++) data[i] = "";
    string q;
    getline(cin, q);
    int n = 0;
    for(int j = 0; j < q.length(); j++){
        int i = (int)q[j];
        if (65 <= i && i <= 90 || 97 <= i && i <= 122)
            data[n].push_back(q[j]);
        else if(data[n].length())
            n++;
    }
    string w = "";
    for(int i = n; i >= 0; i--){
        if(data[i].length()){
            w += data[i] + " ";
        }
    }
    while (w[w.length()] == ' ')
        w.pop_back();
    cout << w << endl;
    return 0;
}

