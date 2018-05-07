//
// Created by defjia on 18-4-29.
//
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <map>
using namespace std;
#define MAXSIZE 100

struct elem{
    char a;
    stack<char> arr;
};
int main(){
    int i = 2, j, n, flag;
    char data, left, right;
    elem a[MAXSIZE], b[MAXSIZE], c[MAXSIZE];
    //elem* c;
    while (i--){
        if(scanf("%d", &n) != 1) exit(3);
        //判断两个n是否相等
        //if(i == 1) c = a;
        //else c = b;
        for(j = 0; j < n; j++){
            if(scanf("%c%c%c", &data, &left, &right) != 3) exit(2);
            printf("-");
            c[j].a = data;
            if (left != '-') c[left].arr.push(data);
            if (right != '-') c[right].arr.push(data);
        }
    }
    printf("++");
    map<char, stack<char>> aa, bb;
    for (i = 0; i < n; i++) aa[a[i].a] = a[i].arr;
    for (i = 0; i < n; i++) bb[b[i].a] = b[i].arr;
    flag = 0;
    for(i = 0; i < n; i++){
        data = a[i].a;
        while (!(aa[data].empty() && bb[data].empty())){
            if(aa[data].top() != bb[data].top()) flag = 1;
            aa[data].pop();
            bb[data].pop();
            if(flag == 1) break;
        }
        if(flag == 1) break;
    }
    if(flag == 0) printf("Yes.\n");
    else printf("No.\n");
    return 0;
}