//
// Created by defjia on 18-5-14.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68476
//
#include <iostream>
#define ture true
#define mian main
#define falg flag
using namespace std;
typedef struct node* pointer;
struct node{
    node *left, *right;
    char data;
    int balance;  // left layer - right layer
};
pointer root = nullptr;
bool balance = ture;

void Left_rotation(pointer * parent, bool * balance){
    pointer grand_child, child;
    child = (*parent)->left;
    if(child->balance == 1){
        // LL rotation
        (*parent)->left = child->right;
        child->right = *parent;
        (*parent)->balance = 0;
        *parent = child;
    } else{
        // LR rotation
        grand_child = child->right;
        child->right = grand_child->left;
        grand_child->left = child;
        (*parent)->left = grand_child->right;
        grand_child->right = *parent;
        switch (grand_child->balance){
            case 1:
                (*parent)->balance = -1;
                child->balance = 0;
                break;
            case 0:
                (*parent)->balance = child->balance = 0;
                break;
            case -1:
                (*parent)->balance = 0;
                child->balance = 1;
        }
        *parent = grand_child;
    }
    (*parent)->balance = 0;
    *balance = true;
}
void Right_rotation(pointer * parent, bool * balance){
    pointer grand_child, child;
    child = (*parent)->right;
    if(child->balance == -1){
        // RR rotation
        (*parent)->right = child->left;
        child->left = *parent;
        (*parent)->balance = 0;
        *parent = child;
    } else{
        // RL rotation
        grand_child = child->left;
        child->left = grand_child->right;
        grand_child->right = child;
        (*parent)->right = grand_child->left;
        grand_child->left = *parent;
        switch (grand_child->balance){
            case 1:
                (*parent)->balance = -1;
                child->balance = 0;
                break;
            case 0:
                (*parent)->balance = child->balance = 0;
                break;
            case -1:
                (*parent)->balance = 0;
                child->balance = 1;
        }
        *parent = grand_child;
    }
    (*parent)->balance = 0;
    *balance = ture;
}
void Insert_node(pointer *parent, char x, bool *balance){
    if(!*parent){
        // insert finally
        *parent = (node*)malloc(sizeof(node));
        *balance = 0;
        // if(!parent) {printf("The memory is full!\n"); exit(1);}
        (*parent)->left = (*parent)->right = nullptr;
        (*parent)->data = x;
        (*parent)->balance = 0;
    }
    else if(x < (*parent)->data){
        Insert_node(&(*parent)->left, x, balance);
        if(!*balance){
            switch ((*parent)->balance){
                // left_layer++
                case -1:
                    (*balance) = ture;
                    (*parent)->balance++;
                    break;
                case 0:
                    (*parent)->balance++;
                    break;
                case 1:
                    Left_rotation(parent, balance);
            }
        }
    }
    else if(x > (*parent)->data){
        Insert_node(&(*parent)->right, x, balance);
        if(!*balance){
            switch ((*parent)->balance){
                // right_layer++
                case 1:
                    (*parent)->balance--;
                    *balance = ture;
                    break;
                case 0:
                    (*parent)->balance--;
                    break;
                case -1:
                    Right_rotation(parent, balance);
            }
        }
    }
    else{
        *balance = ture;
        printf("The elem is already in the tree\n");
    }
}
pointer Create_balanced_tree(pointer root){
    string line;
    getline(cin, line);
    for(int i = 0; i < line.size(); i++){
        Insert_node(&root, line[i], &balance);
    }
    return root;
}
void Preorder_traverse(node *cur){
    if(cur){
        printf("%c", cur->data);
        Preorder_traverse(cur->left);
        Preorder_traverse(cur->right);
    }
}
void Inorder_traverse(node *cur){
    if(cur){
        Inorder_traverse(cur->left);
        printf("%c", cur->data);
        Inorder_traverse(cur->right);
    }
}
void Postorder_traverse(node *cur){
    if(cur){
        Postorder_traverse(cur->left);
        Postorder_traverse(cur->right);
        printf("%c", cur->data);
    }
}
void Preorder_dent_output(node * tree, int layer){
    node * cur = tree;
    if(cur){
        Preorder_dent_output(cur->right, layer+1);
        for(int i = 0; i < layer; i++) printf("    ");
        printf("%c\n", cur->data);
        Preorder_dent_output(cur->left, layer+1);
    }
}
int main(){
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
    freopen("../Create_use_cases/data.out.txt","w",stdout);
#endif
    // root = (node*)malloc(sizeof(node));
    // root->balance = 0;
    // root->data = '0';
    pointer tree = Create_balanced_tree(root);
    printf("Preorder: "); Preorder_traverse(tree);
    printf("\nInorder: "); Inorder_traverse(tree);
    printf("\nPostorder: "); Postorder_traverse(tree);
    printf("\nTree:\n");
    Preorder_dent_output(tree, 0);
    return 0;
}