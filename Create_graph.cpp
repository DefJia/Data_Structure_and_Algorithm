//
// Created by defjia on 18-5-6.
//
#include <cstdlib>
#include <cstdio>
#include <queue>
#define MAXSIZE 100000
using namespace std;
struct EdgeNode{
    struct VertexNode *data;
    struct EdgeNode *next;
}edgeNode;
struct VertexNode{
    int no;
    char data;
    struct EdgeNode *head;
};
struct Graph{
    struct VertexNode node[MAXSIZE];
};

void BFS(Graph &graph, queue<VertexNode*> temp){
    VertexNode* cur;
    EdgeNode* cursor;
    while (!temp.empty()){
        cur = temp.front();
        temp.pop();
        cursor = cur->head;
        while (cursor){
            if(cursor->data->no != -1){
                temp.push(cursor->data);
                cursor->data->no = -1;
                printf("%c", cursor->data->data);
            }
            cursor = cursor->next;
        }
    }
    int i = 0;
    while (graph.node[i].data){
        if(graph.node[i++].no != -1){
            temp.push(graph.node+i-1);
            graph.node[i-1].no = -1;
            printf("%c", temp.front()->data);
            BFS(graph, temp);
        }
    }
}

int main(){
    char a;
    int i = 0;
    Graph graph;
    while(scanf("%c\n", &a) == 1 && a != '*'){
        graph.node[i].data = a;
        graph.node[i].no = i;
        graph.node[i++].head = NULL;
    }
    int b, c;
    EdgeNode* t;
    while(scanf("%d,%d", &b, &c) == 2 && b != -1 && c != -1){
        EdgeNode* tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
        tmp->data = graph.node + c;
        if(graph.node[b].head == NULL) graph.node[b].head = tmp;
        else {
            t = graph.node[b].head;
            tmp->next = t;
            graph.node[b].head = tmp;
        };
        b = b + c; c = b - c; b -= c;
        tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
        tmp->data = graph.node + c;
        if(graph.node[b].head == NULL) graph.node[b].head = tmp;
        else {
            t = graph.node[b].head;
            tmp->next = t;
            graph.node[b].head = tmp;
        };
    }
    //Construction ends.
    printf("the ALGraph is\n");
    for (i = 0; graph.node[i].data; i++){
        printf("%c", graph.node[i].data);
        t = graph.node[i].head;
        while(t){
            printf(" %d", t->data->no);
            t = t->next;
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    queue<VertexNode*> temp;
    temp.push(graph.node+0);
    graph.node[0].no = -1;
    printf("%c", temp.front()->data);
    BFS(graph, temp);
    printf("\n");
    return 0;
}
