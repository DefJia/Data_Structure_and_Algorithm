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
void sort(queue<char> & arr, int * res){
    char tmp[MAXSIZE];
    memset(tmp, 0, MAXSIZE);
    int lkl = arr.size();
    for(int i = 0; i < lkl; i++){
        tmp[i] = arr.front();
        arr.pop();
    }
    int min, mine;
    for(int i = 0; i < lkl; i++){
        mine = 0; min = INF + 1;
        for(int i = 0; i < lkl; i++){
            if(tmp[i] != 'A' && res[tmp[i] - 'a'] < min){
                mine = i;
                min = res[tmp[i] - 'a'];
            }
        }
        arr.push(tmp[mine]);
        tmp[mine] = 'A';
    }
}
int main(){
    int weight[MAXSIZE][MAXSIZE], res[MAXSIZE], flag[MAXSIZE];
    char start_v, q, p;
    int nv, ne, i, w;
    if(scanf("%d,%d,%c\n", &nv, &ne, &start_v) != 3) exit(1);
    // memset(weight, 1, sizeof(weight));
    for(i = 0; i < nv; i++){
        weight[nv+1][i] = -1;
        weight[i][nv+1] = -1;
    }
    //border
    for(i = 0; i < nv; i++) for(int j = 0; j < nv; j++) weight[i][j] = INF;
    for (i = 0; i < nv; i++) res[i] = (i==0? 0 :INF);
    memset(flag, 0, nv); flag[start_v - 'a'] = 1;
    while (ne--){

        if(!ne) scanf("<%c,%c,%d>", &q, &p, &w);
        else scanf("<%c,%c,%d>\n", &q, &p, &w);

        //scanf("<%c,%c,%d>\n", &q, &p, &w);
        weight[q-'a'][p-'a'] = w;
    }
    //Construction
    queue<char> hh;
    char cur;
    hh.push(start_v);
    while(!hh.empty()){
        cur = hh.front();
        hh.pop();
        for(i = 0; i < nv; i++) {
            if (weight[cur - 'a'][i] != INF) {
                if (flag[i] == 0) {
                    flag[i] = 1;
                    hh.push('a' + i);
                }
                if (res[cur - 'a'] + weight[cur - 'a'][i] < res[i]) {
                    res[i] = res[cur - 'a'] + weight[cur - 'a'][i];
                }
            }
        }
        sort(hh, res);
    }
    for(i = 0; i < nv; i++){
        printf("%c:%d\n", 'a' + i, res[i]);
    }
    return 0;
}

