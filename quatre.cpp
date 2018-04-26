#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *pre, *next;
}NODE;

void output( NODE * head )
{
    while ( head->pre != NULL )
    {   head = head->pre;
        printf("%d", head->data);
    }
    printf("\n");
}


int main(){
    int n, k, m;
    NODE *a, *c, *tmp, *r;
    //current temporary, reverse
    scanf("%d,%d,%d", &n, &k, &m);
    if(n * k * m == 0){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    } else if(k > n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    a = ( NODE * ) malloc( sizeof(NODE) );
    c = ( NODE * ) malloc( sizeof(NODE) );
    c = a;
    a->data = 1;
    a->pre = a->next = a;
    for(int i = 2; i <= n; i++){
        tmp = ( NODE * ) malloc( sizeof(NODE) );
        tmp->data = i;
        c->next = tmp;
        tmp->pre = c;
        c = tmp;
    }
    a->pre = c;
    c->next = a;
    //output(a);
    c = a;
    r = a;
    for(int i = 0; i < k - 1; i++){
        r = r->next;
    }
    c = r;
    //start
    while(r->next->data != r->pre->data){
        for(int i = 0; i < m - 1; i++){
            c = c->next;
            r = r->pre;
        }
        if(c->data == r->data){
            printf("%d,", r->data);
            r->next->pre = r->pre;
            r->pre->next = r->next;
        } else{
            printf("%d-%d,", c->data, r->data);
            r->next->pre = r->pre;
            r->pre->next = r->next;
            c->next->pre = c->pre;
            c->pre->next = c->next;
        }
        c = c->next;
        r = r->pre;
    }

    if (m == 1 && r->next->data != r->next->next->data) {

		printf("%d-%d,\n", r->next->data, r->next->next->data);
		return 0;
	}
	printf("%d,\n", r->next->data);

    return 0;
}
