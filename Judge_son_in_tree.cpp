//
// Created by defjia on 18-4-26.
//
#define NON_RECURSION
#define LEN 100
#define NO 0
#define YES 1
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int L[LEN] = {0, 2, 4, 6, 0, 7, 0, 0, 0, 0};
int R[LEN] = {0, 3, 5, 0, 0, 8, 9, 0, 0, 0};
int u, v, i = 9;


#ifdef RECURSION
bool Judge_child(int u, int v){
    if(u == v) return YES;
    if(L[v]) if(Judge_child(u, L[v])) return YES;
    if(R[v]) if(Judge_child(u, R[v])) return YES;
    return NO;
}
int main(){
    if(scanf("%d%d", &u, &v) != 2) exit(1);
    if(u > i || v > i) exit(1);
    if(u == v) return NO;
    if(Judge_child(u, v)) return YES;
    else return NO;
}
#endif

#ifdef NON_RECURSION
int main(){
    queue<int> tmp;
    int p;
    if(scanf("%d%d", &u, &v) != 2) exit(1);
    if(u > i || v > i) exit(1);
    tmp.push(v);
    while(!tmp.empty()){
        p = tmp.front();
        tmp.pop();
        if(L[p]){
            if (L[p] == u){
                p = 0;
                break;
            }
            tmp.push(L[p]);
        }
        if(R[p]){
            if(R[p] == u) {
                p = 0;
                break;
            }
            tmp.push(R[p]);
        }
    }
    if(p == 0) return YES;
    else return NO;
}
#endif
