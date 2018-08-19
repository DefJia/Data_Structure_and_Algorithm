//
// Created by defjia on 18-8-19.
//
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

struct edge{
    edge * next;
    int data;
};
struct vertex{
    int data, num;
    edge * head;
};

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int total;
    cin >> total;
    vertex v[MAX];
    for(int i = 0; i < MAX; i++) v[i].num = 0;
    for (int i = 0; i < total; i++){
        int start, end;
        cin >> start >> end;
        edge * tmp = (edge*)malloc(sizeof(edge));
        tmp->data = end;
        if(!v[start].head){
            v[start].head = tmp;
        } else if(v[start].head->data > end){
            tmp->next = v[start].head;
            v[start].head = tmp;
        } else{
            edge * cur = v[start].head;
            for(int j = 0; j <= v[start].num; j++){
                if(j < v[start].num and cur->data > end){
                    tmp->next = cur->next;
                    cur->next = tmp;
                    break;
                }
                if(j == v[start].num-1){
                    cur->next = tmp;
                    break;
                }
                cur = cur->next;
            }
        }
        edge * tmp2 = (edge*)malloc(sizeof(edge));
        tmp2->data = start;
        if(!v[end].head){
            v[end].head = tmp2;
            tmp2->data = start;
        } else if(v[end].head->data > start){
            tmp2->next = v[end].head;
            v[end].head = tmp2;
        } else {
            edge *cur = v[end].head;
            for (int j = 0; j <= v[end].num; j++) {
                if (j < v[end].num and cur->data > start) {
                    tmp2->next = cur->next;
                    cur->next = tmp2;
                    break;
                }
                if(j == v[end].num-1){
                    cur->next = tmp2;
                    break;
                }
                cur = cur->next;
            }
        }
        v[end].num++;
        v[start].num++;
        // Prepare Graph
    }
    int cnt = 1;
    int max_ = -1;
    while(cnt != 0){
        cnt = 0;
        for (int i = 1; i <= MAX; i++){
            if(v[i].num == 1){
                cnt++;
                v[i].num = 0;
                int flag = 0;
                edge * cur = v[v[i].head->data].head;
                if(v[v[i].head->data].head->data == i){
                    v[v[i].head->data].num--;
                    v[v[i].head->data].head = v[v[i].head->data].head->next;
                    flag = 1;
                    if(!v[v[i].head->data].num)
                        max_ = max(max_, min(i, v[i].head->data));
                    else
                        max_ = max(max_, i);
                }
                for(int j = 0; i < v[v[i].head->data].num && flag == 1; j++){
                    if(cur->next->data == i){
                        cur->next = cur->next->next;
                        v[v[i].head->data].num--;
                        max_ = max(max_, i);
                        break;
                    }
                }
            }
        }
    }
    cout << max_ << endl;
    return  0;
}
