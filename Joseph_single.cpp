#include <stdio.h>
#include <cstdlib>

typedef struct node{
    int data;
    struct node *next;
}NODE;

void output( NODE * head )
{	NODE *h = head;
    while ( head != h)
    {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
	int n, k, m;
    NODE *a, *c, *tmp;
    //main current temporary
    if(scanf("%d,%d,%d", &n, &k, &m) != 3)exit(0);
    if(n < 0 || k < 0 || m < 0){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    } else if(k > n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    a = ( NODE * ) malloc( sizeof(NODE) );
    a->data = 1;
    a->next = a;
    c = a;
    for(int i = 2; i <= n; i++){
        tmp = ( NODE * ) malloc( sizeof(NODE) );
        tmp->data = i;
        c->next = tmp;
        tmp->next = a;
        c = c->next;
    }
    //prepare
    c = a; 
    for(int i = 0; i < k - 1; i++){
    	c = c->next;
    }
    //start
    int fk = 0;
    while(c->next != c){
    	for(int i = 1; i < m - 1; i++){
    		c = c->next;
    	}
    	fk++;
    	if(fk % 10 == 0){
    		printf("%d\n", c->next->data);
    		fk = 0;
    	}else{
			printf("%d ", c->next->data);
    	}
    	c->next = c->next->next;
    	c = c->next;
    }
    printf("%d\n", c->data);
    return 0;
}
/*
43 //c = a; 
50 for(int i = 0; i < m - 1; i++){
61 //c = c->next;
这种情况有一个样例过不了，不知道为什么。
*/

/*
下面这个过了 但不知道和上面有啥区别

#include <stdio.h>
#include <cstdlib>

typedef struct node{
    int data;
    struct node *next;
}NODE;

void output( NODE * head )
{	NODE *h = head;
    while ( head != h)
    {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
	int n, k, m;
    NODE *a, *c, *tmp;
    //main current temporary
    if(scanf("%d,%d,%d", &n, &k, &m) != 3)exit(0);
    if(n * k * m == 0){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    } else if(k > n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    a = ( NODE * ) malloc( sizeof(NODE) );
    a->data = 1;
    a->next = a;
    c = a;
    for(int i = 2; i <= n; i++){
        tmp = ( NODE * ) malloc( sizeof(NODE) );
        tmp->data = i;
        c->next = tmp;
        tmp->next = a;
        c = c->next;
    }
    //prepare
    c = a;
    for(int i = 0; i < k - 1; i++){
    	c = c->next;
    }
    //start
    int fk = 0;
    while(c->next != c){
    	for(int i = 1; i < m - 1; i++){
    		c = c->next;
    	}
    	fk++;
    	if(fk % 10 == 0){
    		printf("%d\n", c->next->data);
    		fk = 0;
    	}else{
			printf("%d ", c->next->data);
    	}
    	c->next = c->next->next;
    	c = c->next;
    }
    printf("%d\n", c->data);
    return 0;
}
*/