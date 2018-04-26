//
// Created by defjia on 18-4-15.
//
#include <cstdlib>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
typedef struct node{
    struct node *left, *right;
    char data;
}Tree;
Tree *Create(string in, string post){
    Tree *root = (node*)malloc(sizeof(node));
    root->data = post.back();
    if(in.size() != 1 && post.size()) {
        int index = in.find(root->data);
        string lin, rin, lpost, rpost;
        lin = in.substr(0, index);
        rin = in.substr(index + 1, in.size() - index - 1);
        lpost = post.substr(0, index);
        rpost = post.substr(index, in.size() - index - 1);
        //cout << rin << lin << lpost << rpost;
        if (lin.size() && lpost.size()) root->left = Create(lin, lpost);
        if (rin.size() && rpost.size()) root->right = Create(rin, rpost);
    }
    return root;
}
void layer_traverse(Tree *tree){
    queue<Tree*> record;
    record.push(tree);
    Tree *cur = tree;
    cout << cur->data;
    while (cur != NULL && !record.empty()){
        cur = record.front(); record.pop();
        if(cur->left != NULL){ cout << cur->left->data; record.push(cur->left);}
        if(cur->right != NULL) {cout << cur->right->data; record.push(cur->right);}
    }
    cout << "\n";
}
int main(){
    string in, post;
    getline(cin, in); getline(cin, post);
    Tree *tree = Create(in, post);
    layer_traverse(tree);
    return 0;
}
