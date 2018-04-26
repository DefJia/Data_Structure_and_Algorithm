/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		  sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void multiplication( NODE * h1, NODE * h2, NODE * h3){
    NODE *pa = h1, *pb = h2, *pc = h3;
    NODE *tmp1;
    int q = 0;


    while(pa->next != NULL){
        //pa = h1;
        pb = h2;
        pa = pa->next;
        if (pa->coef == 0 && q == 1)continue;
        pc = h3;
        while(pb->next != NULL){
            pb = pb->next;
            int te = pb->exp + pa->exp;
            int tc = pb->coef * pa->coef;
            if(tc == 0 && q == 1)continue;//q?
            NODE *tmp2;
            while(pc != NULL){
                tmp2 = pc;//pointer
                pc = pc->next;
                if(pc == NULL){
                    tmp1 = (NODE*)malloc(sizeof(NODE));
                    if(tc == 0 && q == 0){
                        tmp1->exp = 0;
                        q = 1;
                    }
                    else
                        tmp1->exp = te;
                        tmp1->coef = tc;
                        tmp1->next = pc;
                        tmp2->next = tmp1;
                        pc = tmp2;
                        break;
                }
                if(pc->exp < te)continue;
                if(pc->exp == te){
                    pc->coef += tc;
                    if(pc->coef == 0 && te != 0){
                        tmp2->next = pc->next;
                    }
                    pc = tmp2;
                    break;
                }
                if(pc->exp > te){
                    tmp1 = (NODE*)malloc(sizeof(NODE));
                    if(tc == 0 && q == 0){
                        tmp1->exp = 0;
                        q = 1;
                    }
                    else
                        tmp1->exp = te;
                        tmp1->coef = pa->coef * pb->coef;
                        tmp1->next = pc;
                        tmp2->next = tmp1;
                        pc = tmp2;
                        break;
                }
            }
        }
    }
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
/*
void multiplication( NODE * h1, NODE * h2, NODE * h3){
    NODE *pa = h1, *pb = h2, *pc = h3;
    NODE *tmp;
    int maxExp, i, k, al, bl;

    for (pa = h1; pa ->next != NULL; pa = pa->next);
    for (pb = h2; pb ->next != NULL; pb = pb->next);
    al = pa ->exp;
    bl = pb ->exp;

    if (al >= 0 && bl >= 0){
        maxExp = al + bl;
        *tmp = ( NODE * ) malloc( sizeof(NODE) );
        //float * tmp = new float[maxExp + 1];
        //float tmp[maxExp + 1];

        //for(i = 0; i < maxExp; i++)tmp[i] = 0.0;
        pa = h1 ->next;
        while (pa != NULL){
            pb = h2 ->next;
            while (pb != NULL){
                k = pa ->exp + pb ->exp;
                tmp[k] = tmp[k] + pa->coef * pb->coef;
                pb = pb->next;
            }
            pa = pa->next;
        }
        for(i = 0; i <= maxExp; i++){
            if (tmp[i]){
                //pc->next = new NODE;
                 pc->next = ( NODE * ) malloc( sizeof(NODE) );
                if(!pc->next){
                    printf("Malloc failed.2");
                    exit(1);
                }
                pc = pc->next;
                pc->coef = tmp[i];
                pc->exp = i;
            }
        }
        //delete [] tmp;
    }
    pc->next = NULL;
}
*/
