#include<stdio.h>  
#include<string.h>   
#include<stdlib.h>  
#define vexnum 500  
typedef struct node{  
    char data;  
    int link;  
    int flag;  
    int g[vexnum];  
    struct node *next;  
}node;  
  
typedef struct node1{  
    int jiedian;  
    struct node1 *link1;  
    struct node1 *link2;  
}node1;  
  
int i,j,y,z;  
int count=0;  
char x;  
int visited[vexnum];  
node *a[vexnum],*b[vexnum];  
node *p,*p1;  
node1 *q,*q1;  
node1 *head,*head1,*end;  
  
void condition1(){  
    while(scanf("%c\n",&x),x!='*'){  
        a[count]=(node*)malloc(sizeof(node));  
        a[count]->data=x;  
        a[count]->flag=0;  
        a[count]->next=NULL;  
        b[count]=a[count];  
        count++;  
    }     
}  
  
void condition2(){  
    while(scanf("%d,%d",&y,&z),y!=-1&&z!=-1){  
        p=(node*)malloc(sizeof(node));  
        p->link=z;  
        p->next=a[y]->next;  
        a[y]->next=p;  
        a[y]->g[a[y]->flag]=p->link;  
        a[y]->flag++;  
        p=(node*)malloc(sizeof(node));  
        p->link=y;  
        p->next=a[z]->next;  
        a[z]->next=p;  
        a[z]->g[a[z]->flag]=p->link;  
        a[z]->flag++;  
    }  
}  
  
void printf(){  
    printf("the ALGraph is\n");  
    for(i=0;i<count;i++){  
        p=a[i]->next;  
        printf("%c",a[i]->data);  
        while(p!=NULL){         
            printf(" %d",p->link);  
            p=p->next;  
        }   
        printf("\n");  
    }  
    q=(node1*)malloc(sizeof(node1));  
    q->link1=NULL;  
    q1=(node1*)malloc(sizeof(node1));  
    q1->link2=NULL;  
    end=q;  
    head=q1;  
    end->link2=head;  
    head->link1=end;  
    head1=head;  
    printf("the Breadth-First-Seacrh list:");  
    for(i=0;i<count;i++){  
        if(visited[i]!=1){  
            visited[i]=1;  
            printf("%c",a[i]->data);   
            q=(node1 *)malloc(sizeof(node1));   
            q->jiedian=i;  
            end->link2=q;  
            q->link1=end;  
            q->link2=head1;  
            head1->link1=q;  
            head1=end->link2;          
            q1=head->link1;  
            while(q1!=end){  
                p1=a[q1->jiedian]->next;  
                while(p1!=NULL){  
                    if(visited[p1->link]!=1){  
                        printf("%c",a[p1->link]->data);  
                        visited[p1->link]=1;  
                        q=(node1*)malloc(sizeof(node1));  
                        q->jiedian=p1->link;  
                        end->link2=q;  
                        q->link1=end;  
                        q->link2=head1;  
                        head1->link1=q;  
                        head1=end->link2;  
                    }  
                p1=p1->next;  
                }  
                q1=q1->link1;  
            }  
        }  
    }   
}  
  
int main(){  
    memset(visited,0,sizeof(visited));  
    condition1();  
    condition2();  
    printf();  
    printf("\n");  
}  
