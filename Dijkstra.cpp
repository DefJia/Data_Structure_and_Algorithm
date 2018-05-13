//
// Created by defjia on 18-5-7.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72685
//
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXSIZE 26
#define INF 99999
using namespace std;
int main(){
    int weight[MAXSIZE][MAXSIZE], res[MAXSIZE], flag[MAXSIZE];
    char start_v, q, p;
    int nv, ne, i, w;
    if(scanf("%d,%d,%c\n", &nv, &ne, &start_v) != 3) exit(1);
    // memset(weight, 1, sizeof(weight));
    for(i = 0; i < nv; i++) for(int j = 0; j < nv; j++) weight[i][j] = INF;
    for (i = 0; i < nv; i++) res[i] = (i==0? 0 :INF);
    memset(flag, 0, nv);
    while (ne--){
        if(!ne) scanf("<%c,%c,%d>", &q, &p, &w);
        else scanf("<%c,%c,%d>\n", &q, &p, &w);
        weight[q-'a'][p-'a'] = w;
    }
    //Construction
    int y;
    for(i = 0; i < nv; i++){
        int x, m = INF;
        for(y = 0; y < nv; y++){
            if(!flag[y] && res[y] <= m){
                m = res[y];
                x = y;
            }
        }
        flag[x] = 1;
        for(y = 0; y < nv; y++) res[y] = min(res[y], res[x] + weight[x][y]);
    }
    for(i = 0; i < nv; i++){
        printf("%c:%d\n", 'a'+i, res[i]);
    }
    return 0;
}

