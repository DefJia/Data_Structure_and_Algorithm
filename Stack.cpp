#include <stdio.h>
#include <cstdlib>
#define INIT_SIZE 100
#define INCREMENT 10

typedef unsigned int ELEM;

typedef struct{
    ELEM *top;
    ELEM *base;
    int size;
}Stack;

void InitStack(Stack &S){
    S.base = (ELEM *)malloc(INIT_SIZE * sizeof(ELEM));
    if(!S.base){exit(0);}
    S.top = S.base;
    S.size = INIT_SIZE;
}

void GetTop(Stack &S, ELEM &e){
    if(S.top == S.base){
        printf("stack is empty!\n");
        return ;
    }
    e = *(S.top - 1);
}

void Push(Stack &S, ELEM e){
    if(S.top - S.base >= S.size){
        S.base = (ELEM *)realloc(S.base, (S.size + INCREMENT) * sizeof(ELEM));
        if(!S.base)exit(0);
        S.top = S.base + S.size;//deletable
        S.size += INCREMENT;
    }
    *S.top++ = e;//指针加减
}

void Pop(Stack &S, ELEM &e){
    if(S.top == S.base)return;
    e = *--S.top;
}

int main(){
    Stack test;
    InitStack(test);
    Push(test, 1);
    Push(test, 2);
    Push(test, 3);
    ELEM e;
    Pop(test, e);
    printf("%d\n", e);
}