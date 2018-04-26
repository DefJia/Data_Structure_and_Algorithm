#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void Create(NODE *un){
    int m, y, z;
    scanf("%d", &m);
    NODE *p = un;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &y, &z);
        p->next = ( NODE * ) malloc( sizeof(NODE) );
        p->next->coef = y;
        p->next->exp = z;
        p = p->next;
        p->next = NULL;
    }
}

int cmp(int a, int b){
    if(a == b)return 0;
    if(a < b)return -1;
    if(a > b)return 1;
}

void Add(node *a, node *b)
{
    NODE *p, *q, *ha, *temp;
    int  tc = 0;
    p = a->next;
    q = b->next;
    ha = a;

    while (p && q){
        if (p->exp < q->exp)
        {
            ha->next = p;
            ha = p;
            p = p->next;
        }
        else if (p->exp > q->exp)
        {
            ha->next = q;
            ha = q;
            q = q->next;
        }
        else
        {
            tc = p->coef + q->coef;
            if (tc)
            {
                p->coef = tc;
                ha->next = p;
                ha = p;
                p = p->next;
                temp = q->next;
                free(q);
                q = temp;
            }
            else
            {
                temp = p->next;
                free(p);
                p = temp;
                temp = q->next;
                free(q);
                q = temp;
            }
        }
    }
    ha->next = p?p:q;
}

void Output( NODE * head ){
    if (head->next == NULL){
        printf("<0,0>");
    }
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>", head->coef, head->exp );
        if(head->next !=NULL){
            printf(",");
        }
    }
    printf("\n");
}

int main(){
    int q;
    NODE *a, *b, *c, *d;
    scanf("%d", &q);
    if(q == 0){exit(0);}

    a = ( NODE * ) malloc( sizeof(NODE) );
    Create(a);
    b = ( NODE * ) malloc( sizeof(NODE) );
    Create(b);
    c = ( NODE * ) malloc( sizeof(NODE) );
    Create(c);

    Output(a);
    Output(b);
    Output(c);

    Add(a ,b);
    Output(a);

    Add(a, c);
    Output(a);

    return 0;
}
