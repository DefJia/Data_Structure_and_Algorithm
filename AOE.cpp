//
// Created by defjia on 18-5-20.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68463
/*
9,11
a,b,c,d,e,f,g,h,k
<0,1,6>,<0,2,4>,<0,3,5>,<1,4,1>,<2,4,1>,<4,6,8>,<4,7,7>,<3,5,2>,<5,7,4>,<6,8,2>,<7,8,4>
*/
//
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#define ture true
#define mian main
#define falg flag
#define MAXSIZE 1000
#include <queue>
#include <iostream>
using namespace std;
struct Edge_node{
    int data, weight;
    Edge_node * next;
};
struct Vertex_node{
    string name;
    int index;
    int flag;
    Edge_node * next;
};
int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    Vertex_node point[MAXSIZE];
    Vertex_node re_point[MAXSIZE];
    int edge[MAXSIZE][6];
    int en, vn;
    if(scanf("%d,%d\n", &vn, &en) != 2) exit(1);
    for(int i = 0; i < vn; i++) {point[i].index = i; point[i].flag = 0;}
    for(int i = 0; i < vn; i++) {re_point[i].index = i; re_point[i].flag = 0;}
    string line;
    getline(cin, line);
    int s, e, w;
    for(int i = 0; i < en; i++){
        getchar();
        if(scanf("%d,%d,%d", &s, &e, &w) != 3) exit(3);
        getchar();getchar();
        edge[i][0] = s; edge[i][1] = e; edge[i][2] = w;
        //
        Edge_node * node = (Edge_node*)malloc(sizeof(Edge_node));
        node->weight = w;
        node->data = e;
        Edge_node * cur = point[s].next;
        if(cur == nullptr) point[s].next = node;
        else{
            while (cur->next != nullptr) cur = cur->next;
            cur->next = node;
        }
        //
        node = (Edge_node*)malloc(sizeof(Edge_node));
        node->weight = w;
        node->data = s;
        cur = re_point[e].next;
        if(cur == nullptr) re_point[e].next = node;
        else{
            while (cur->next != nullptr) cur = cur->next;
            cur->next = node;
        }
    }
    // Construction
    queue<Vertex_node*> early;
    int early_time[MAXSIZE];
    memset(early_time, 0, sizeof(early_time));
    point[0].flag = 1;
    early.push(point+0);
    while(!early.empty()){
        Vertex_node * tmp = early.front();
        early.pop();
        Edge_node * cur = tmp->next;
        while (cur != nullptr){
            early_time[cur->data] = early_time[cur->data] > early_time[tmp->index] + cur->weight? early_time[cur->data]: early_time[tmp->index] + cur->weight;
            if(point[cur->data].flag == 0){
                early.push(point+cur->data);
            }
            cur = cur->next;
        }
    }
    for(int i = 0; i < en; i++){
        edge[i][3] = early_time[edge[i][1]] - edge[i][2];
    }
    // early
    int v_max = 0;
    for(int i = 0; i < vn; i++) v_max = early_time[i] > v_max? early_time[i]: v_max;
    queue<Vertex_node*> late;
    int late_time[MAXSIZE];
    memset(late_time, 0, sizeof(late_time));
    for(int i = 0; i < MAXSIZE; i++) late_time[i] = v_max;
    for(int i = 0; i < vn; i++) re_point[i].flag = 0;
    re_point[vn-1].flag = 1;
    late.push(re_point+vn-1);
    while(!late.empty()){
        Vertex_node * tmp = late.front();
        late.pop();
        Edge_node * cur = tmp->next;
        while (cur != nullptr){
            late_time[cur->data] = late_time[cur->data] < late_time[tmp->index] - cur->weight? late_time[cur->data]: late_time[tmp->index] - cur->weight;
            if(re_point[cur->data].flag == 0){
                late.push(re_point+cur->data);
            }
            cur = cur->next;
        }
    }
    for(int i = 0; i < en; i++){
        edge[i][4] = late_time[edge[i][1]] - edge[i][2];
    }
    // Cal
    for(int i = 0; i < en; i++) edge[i][5] = edge[i][3] - edge[i][4];
    return 0;
}

