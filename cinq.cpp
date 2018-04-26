/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

/*
设一带头结点的双向循环链表表示的线性表：
L =（a1, a2, …… , an）
请写出一个时间复杂度为O(n)的算法，将L改造为：
L =（a1, a2, ……, an-1, an, an-1, ……, a2, a1）
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLNode {
    ElemType        data;      // 数据域
    struct DuLNode  *prior;	   // 指向前驱的指针域
    struct DuLNode  *next;	   // 指向后继的指针域
} DuLNode, * DuLinkList;

// 函数原型
void out_next(DuLinkList);
void out_prior(DuLinkList);
void rcopy(DuLinkList);		//这是你要编写的函数

// 函数定义
void out_next(DuLinkList DHead)
{	DuLinkList p = DHead->next;
	while ( p != DHead )
	{	printf("%d,", p->data);
		p = p->next;
	}
	printf("\n");
}
void out_prior(DuLinkList DHead)
{	DuLinkList p = DHead->prior;
	while ( p != DHead )
	{	printf("%d,", p->data);
		p = p->prior;
	}
	printf("\n");
}

int main()
{	DuLinkList DHead, p;
	int num;

	DHead = (DuLNode*)malloc( sizeof(DuLNode));
	DHead->data = -1;
	DHead->prior = DHead->next = DHead;   	// 生成表头

	scanf("%d", &num);
	while ( num != -1 )
	{	p = (DuLNode*)malloc( sizeof(DuLNode));
		p->data = num;
		p->next = DHead->next;	// 1.链接p的next链
		DHead->next = p;		// 2.链接DHead的next链
		p->next->prior = p;		// 3.链接p的next的prior链
		p->prior = DHead;		// 4.链接p的prior链
		scanf("%d", &num);
	}
	printf("Link  next:");	out_next( DHead );
	printf("Link prior:");	out_prior( DHead );
	rcopy( DHead );
	printf("NewL  next:");	out_next( DHead );
	printf("NewL prior:");	out_prior( DHead );
	return 0;
}
/**************************************
void rcopy(DuLinkList DHead)
{
    This function is wating for you.
}
***************************************/
/*
void rcopy(DuLinkList DHead){
    DuLinkList r, w, t;
    //read, write, temporary
    r = DHead;
    while(r->next!=NULL){
        r = r->next;
    }
    w = r;
    while(r->prior!=DHead){
        t = (DuLNode*)malloc( sizeof(DuLNode));
        r = r->prior;
        t->data = r->data;
        w->next = t;
        t->prior = w;
        w = w->next;
    }
}
*/
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void rcopy(DuLinkList DHead){
    DuLinkList r=NULL, w=NULL, t=NULL;
    //read, write, temporary
    if(DHead->next==DHead)return;
    r = DHead;
    w = DHead;
    r = r->next;
    while(r->next&&r->next != DHead   ){
        t = (DuLNode*)malloc( sizeof(DuLNode));
        t->data = r->data;
        t->next = w;
        w->prior = t;
        w = t;
        r = r->next;
    }
    if(DHead->next->next!=DHead){
        r->next = t;
        t->prior = r;
    }
}

