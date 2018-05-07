#include<stdio.h>
#include<stdlib.h>

#define OK      1
#define ERROR   0
#define TRUE    1
#define FALSE   0
#define OVERFLOW -1

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S){
    S.base=(SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status DetroyStack( SqStack  &S )
{  if ( ! S.base )
        return ERROR;
    //若栈未建立（尚未分配栈空间）
    free ( S.base );                           //回收栈空间
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack( SqStack  &S )
{  if ( ! S.base )
        return ERROR;
    // 若栈未建立（尚未分配栈空间）
    S.top = S.base;
    return OK;}  //ClearStack

Status GetTop( SqStack S, SElemType &e )
{  if ( S.top == S.base )
        return ERROR;       //栈空
    e = *(S.top-1);
    return OK;}  //GetTop

Status Push ( SqStack &S, SElemType e )
{   //将元素e插入栈中，使其成为新的栈顶元素
    if ( S.top-S.base >= S.stacksize ) // 若栈满则追加存储空间
    {  S.base =  (SElemType * ) realloc ( S.base,
                                          ( S.stacksize + STACKINCREMENT ) * sizeof( SElemType ) );
        if  ( ! S. base )    exit(OVERFLOW);   //存储分配失败
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;   }
    * S.top ++ = e;      //元素e 插入栈顶，后修改栈顶指针
    return OK;}  //Push

Status  Pop( SqStack &S,  SElemType &e )
{  if ( S.top==S.base )
        return ERROR;     // 栈空
    e = * -- S.top;   // --S.top; e=*S.top;
    return OK;}

Status StackEmpty(SqStack S)
{
    //若栈S为空栈，则返回TRUE，否则返回FALSE
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}


int main(){
    SElemType e;
    int N;
    SqStack S;
    InitStack(S);
    scanf("%d",&N);
    while(N){
        Push(S, N % 8);
        N = N / 8;
    }
    while(!StackEmpty(S)){
        Pop(S, e);
        printf("%d", e);
    }
}


