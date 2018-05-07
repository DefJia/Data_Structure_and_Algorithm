//
// Created by defjia on 18-4-27.
//
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef struct node{
    char data;
    struct node* child[MAXSIZE];
}NODE;
void Output(NODE* tree, int layer){
    cout << tree->data;
    for(int i = 0; tree->child[i]; i++){
        Output(tree->child[i], layer++);
    }
}
int main(){
    stack<NODE*> tmp;
    int flag = 0, i;
    char a = getchar();
    NODE* root;
    while (a != '\n'){
        if(a == '(') flag = 0;
        if(a == ')') tmp.pop();
        if(a >= 'a' && a <= 'z'){
            NODE* p = (NODE*)malloc(sizeof(NODE));
            if(root->data == 'A') root = p;
            p->data = a;
            tmp.push(p);
            for (i = 0; tmp.top()->child[i]; i++);
            tmp.top()->child[i] = p;
            //flag = 0;
        }
        a = getchar();
    }
    Output(root, 0);
    return  0;
}
