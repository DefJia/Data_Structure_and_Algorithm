//
// Created by defjia on 18-5-14.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68476
//
#include <iostream>
#include <stdio.h>
using namespace std;
struct node{
    node *left, *right;
    char data;
};
node * Create_balanced_tree(){

}
void Dent_output(node *tree, int a){
    node *cur = tree;
    if(cur){
        for(int i = 0; i < a; i++) printf("    ");
        a++;
        printf("%c\n", cur->data);
        Dent_output(cur->left, a);
        Dent_output(cur->right, a);
    }
}
int main(){
    node * tree;
    tree = Create_balanced_tree();
    Dent_output(tree, 0);
}
