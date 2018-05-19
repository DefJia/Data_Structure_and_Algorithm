//
// Created by defjia on 18-5-19.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72430
// (a,(b,(c),(d)),(f,(g),(h),(i)))
//
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <cstring>
#define MAX_DEGREE 1000
using namespace std;
#define mian main
#define ture true
struct node{
    char data = NULL;
    int degree = 0;
    node * first_child = nullptr, * next_sibling = nullptr;
};
void Output_tree(node* tree, int layer){
    node * cur = tree;
    if(cur){
        for(int i = 0; i < layer; i++) printf("    ");
        printf("%c\n", cur->data);
        layer++;
        cur = cur->first_child;
        while (cur){
            Output_tree(cur, layer);
            cur = cur->next_sibling;
        }
    }
}
int Traverse(node * tree, int * degree, int max){
    if(tree){
        degree[tree->degree]++;
        max = max > tree->degree? max: tree->degree;
        int max1;
        max1 = Traverse(tree->first_child, degree, max);
        max = max > max1? max: max1;
        max1 = Traverse(tree->next_sibling, degree, max);
        max = max > max1? max: max1;
    }
    return max;
}
int main(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    stack<node*> record;
    node * tree = (node*)malloc(sizeof(node));
    node * cur = tree;
    record.push(cur);
    char in;
    string input;
    getline(cin, input);
    int i = 0;
    in = input[i++];
    while (i <= input.size()){
        if(in == '(') {
            cur = record.top();
            cur->degree++;
        }
        else if(in == ')') {
            record.pop();
        }
        else if(in - 'a' < 26 && in - 'a' >= 0){
            node * tmp = (node*)malloc(sizeof(node));
            tmp->degree = 0;
            tmp->data = in;
            tmp->next_sibling = nullptr;
            tmp->first_child = nullptr;
            if(cur->first_child == nullptr) cur->first_child = tmp;
            else{
                cur = cur->first_child;
                while (cur->next_sibling) cur = cur->next_sibling;
                cur->next_sibling = tmp;
            }
            record.push(tmp);
        }
        in = input[i++];
    }
    Output_tree(tree->first_child, 0);
    int degree[MAX_DEGREE];
    memset(degree, 0, sizeof(degree));
    int max_degree = Traverse(tree->first_child, degree, 0);
    printf("Degree of tree: %d\n", max_degree);
    for(i = 0; i <= max_degree; i++){
        printf("Number of nodes of degree %d: %d\n", i, degree[i]);
    }
}

