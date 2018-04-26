/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

void output( NODE * );
void change( int, int, NODE * );

void output( NODE * head )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<50 )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m;
	NODE * head;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;
	change( n, m, head );
	output( head );
	return 0;
}

void change(int d, int s, NODE *h){
    //dividend, divisor
    NODE *w = h, *f, *tmp;
    //write, find, temporary
    int arr[50];
    int i = 0;
    int j = 0;
    while(d && i < 50){
        arr[i++] = d;
        for(j = 0, f = h->next; f != NULL && j < i-1; f = f->next){
            if (arr[j++] == d){
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
/*
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
*/
