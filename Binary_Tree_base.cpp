#include <cstdlib>
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#define MAXSIZE 1000
using namespace std;
typedef struct node{
	struct node *left, *right;
	char data;
}Tree;
Tree* Create(){
	queue<Tree*> record;
	queue<char> raw;
	char d = getchar();
	while(d != '\n') {raw.push(d); d = getchar();}

	Tree *root = (node*)malloc(sizeof(node));
	root->data = raw.front(); raw.pop(); 
	record.push(root);
	while(!record.empty() && !raw.empty()){
		Tree *q = record.front(); record.pop();
		Tree *nl = (node*)malloc(sizeof(node));
		nl->data = raw.front(); raw.pop();
		if (nl->data != '#') q->left = nl;
		record.push(nl);
		if(!raw.empty()){
			Tree *nr = (node*)malloc(sizeof(node));
			nr->data = raw.front(); raw.pop();
			if (nr->data != '#') q->right = nr;
			record.push(nr);
		}
	}
	return root;
}
/*
void DFS_traverse(Tree *tree){
	stack<Tree*> record;
    stack<int> index;
    int last = -1;
	int layer = 0;
	Tree *cur = tree;
	while(!record.empty() || cur){
		while(cur){
			int i = layer; while(i--) printf("   ");
			printf("%c\n", cur->data);
			record.push(cur);
			cur = cur->left;
            if(cur != NULL) layer++;
		}
		if(!record.empty()){
			cur = record.top(); record.pop();
			cur = cur->right;
            layer = record.size() + 1;
		}
	}
}
*/
void Dent_output(Tree *tree, int a){
    Tree *cur = tree;
    if(cur){
        for(int i = 0; i < a; i++) printf("    ");
        a++;
        printf("%c\n", cur->data);
        Dent_output(cur->left, a);
        Dent_output(cur->right, a);
    }
}
void Preorder_traverse(Tree *cur){
    if(cur){
        printf("%c", cur->data);
        Preorder_traverse(cur->left);
        Preorder_traverse(cur->right);
    }
}
void Inorder_traverse(Tree *cur){
    if(cur){
        Inorder_traverse(cur->left);
        printf("%c", cur->data);
        Inorder_traverse(cur->right);
    }
}
void Postorder_traverse(Tree *cur){
    if(cur){
        Postorder_traverse(cur->left);
        Postorder_traverse(cur->right);
        printf("%c", cur->data);
    }
}
int Cal_leaf(Tree *cur){
    if(cur == NULL)
        return  0;
    if(cur->right == NULL && cur->left == NULL)
        return 1;
    return (Cal_leaf(cur->left) + Cal_leaf(cur->right));
}
void Swap_children(Tree *tree){
    Tree *tmp;
    if(tree){
        tmp = tree->left;
        tree->left = tree->right;
        tree->right = tmp;
        Swap_children(tree->left);
        Swap_children(tree->right);
    }
}
int main(){
	Tree *tree;
	tree = Create();
    cout << "BiTree\n";
    Dent_output(tree, 0);
    cout << "pre_sequence  : ";
    Preorder_traverse(tree);
    cout << "\nin_sequence   : ";
    Inorder_traverse(tree);
    cout << "\npost_sequence : ";
    Postorder_traverse(tree);
    cout << "\nNumber of leaf: " << Cal_leaf(tree);
    Swap_children(tree);
    cout << "\nBiTree swapped\n";
    Dent_output(tree, 0);
    cout << "pre_sequence  : ";
    Preorder_traverse(tree);
    cout << "\nin_sequence   : ";
    Inorder_traverse(tree);
    cout << "\npost_sequence : ";
    Postorder_traverse(tree);
    cout << "\n";
}