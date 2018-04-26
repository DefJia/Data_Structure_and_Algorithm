/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );

void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do	{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;

}

int main()
{   int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	pring = find( head, &n );
	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}

int read(NODE *a, int i){
    for(int j = 0; j < i + 1; j++){
        a = a->next;
    }
    //printf("read%d\n", i + 1);
    return a->data;
}

void write(NODE *a, int n){
    while(a->next != NULL){
        a = a->next;
    }
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->data = n;
    tmp->next = NULL;
    a->next = tmp;
    //printf("write%d\n", n);
}

void change(int d, int s, NODE *h){
    //dividend, divisor
    NODE *w = h, *f, *tmp;
    //write, find, temporary
    NODE *r = (NODE *)malloc(sizeof(NODE));
    r->next = NULL;
    r->data = -1;
    //restore
    int i = 0;
    int j = 0;
    while(d){
        write(r, d);
        i++;
        for(j = 0, f = h->next; f != NULL && j < i-1; f = f->next){
            int t = read(r, j++);
            if (t == d){
                w->next = f; return;
            }
        }
        tmp = (NODE *)malloc(sizeof(NODE));
        d *= 10;
        tmp->data = d / s;
        //printf("%d, %d\n",d, d/s);
        d %= s;
        //if(!d){w->next=NULL;}
        w->next = tmp;
        w = tmp;
        w->next = NULL;
    }
}

NODE * find( NODE * head, int * n )
{
	int j = 1, i = 1;
	NODE *c = head->next;

	while(c->next != NULL){
		i = 1;
		for(NODE *f = head->next; f != c || f == c->next; f = f->next, i++){
			//i = xth elem
			if(f == c->next){
				*n = j - i+1;
				return f;
			}
		}
		j++;
		c = c->next;
		//j = xth elem
	}
	*n = 0;
	return NULL;
}