//
// Created by defjia on 18-4-28.
//
#define MAXSIZE 50
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
typedef struct elem{
    int edge[MAXSIZE][2];
};
int main(){
    elem arr[MAXSIZE];
    int status[MAXSIZE];
    memset(status, 0, sizeof(status));
    int n, m, i, num = 0;
    if(scanf("%d%d", &n, &m) != 2) exit(2);
    for(i = 0; i < n; n++) {
        elem tmp;
        arr[i] = tmp;
    }
    while (m--){
        int ttt;
        if(scanf("%d", &ttt) != 1) exit(2);
        switch (ttt){
            case 1:{
                int q, p;
                if(scanf("%d%d", &q, &p) != 2) exit(2);
                status[num++] = 1;
                for(i = 0; arr[q].edge[i++][])
                    arr[q].edge[];//1->2
                break;
            }
            case 2:{
                int q;
                if(scanf("%d", &q) != 1) exit(2);
                queue<int> tmp;
                tmp.push(q);
                while (!tmp.empty()){
                    //arr[q]
                    int z = tmp.front();
                    tmp.pop();
                    for (i = 0; arr[z].edge.front() )
                }
                status[num++] = 1;
                break;
            }
            case 3:{
                int q;
                if(scanf("%d", &q) != 1) exit(2);
                for(i = 0; i < q; i++) status[num-1-i] = 0-status[num-i];
                status[num++] = 1;
                break;
            }
        }
    }
}