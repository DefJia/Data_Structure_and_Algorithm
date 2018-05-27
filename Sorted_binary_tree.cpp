//
// Created by defjia on 18-5-20.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=70937
//
// #define LOCAL
#include <cstdlib>
#include <cstdio>
#define ture true
#define mian main
#define falg flag
struct node{
    int data;
    node * left, * right;
};
void Preorder_dent_output(node * tree, int layer){
    node * cur = tree;
    if(cur){
        Preorder_dent_output(cur->left, layer+1);
        for(int i = 0; i < layer; i++) printf("    ");
        printf("%d\n", cur->data);
        Preorder_dent_output(cur->right, layer+1);
    }
}
void Inorder_traverse(node * tree){
    node * cur = tree;
    if(cur){
        Inorder_traverse(cur->left);
        printf(" %d", cur->data);
        Inorder_traverse(cur->right);
    }
}
int mian(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
    freopen("../Create_use_cases/data.out.txt","w",stdout);
#endif
    int n;
    if(scanf("%d", &n) != 1) exit(1);
    node * tree = (node*)malloc(sizeof(node));
    tree->data = n;
    if(scanf("%d", &n) != 1) exit(1);
    while (n){
        node * novel = (node*)malloc(sizeof(node));
        novel->data = n;
        node * cur = tree;
        while (true){
            if(n < cur->data) {if(cur->left) cur = cur->left; else break;}
            else {if(cur->right) cur = cur->right; else break;}
        }
        if(n < cur->data) cur->left = novel;
        else cur->right = novel;
        if(scanf("%d", &n) != 1) exit(1);
    }
    // Construction
    Preorder_dent_output(tree, 0);
    printf("\n");
    Inorder_traverse(tree);
    printf("\n");
    return 0;
}

