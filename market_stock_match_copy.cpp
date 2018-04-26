//
// Created by defjia on 18-4-18.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int min(int a , int b)
{
    return a<=b?a:b;
}

struct order
{
    int orderid;
    int stock;
    float price;
    int quantity;
    char type;
    struct order *next;
};

int main()
{
    int j,k,type,id,quantity,count=1,temquantity,flag=0;
    float price=0.0,temprice=0.0,i=0.0;
    char bs,aaa;
    struct order *p,*q,*tem3,*front1=NULL,*rear1=NULL,*front2=NULL,*rear2=NULL;
    struct order *temp;

    front1=rear1=(struct order*)malloc(sizeof(struct order));
    front2=rear2=(struct order*)malloc(sizeof(struct order));
    front1->next=NULL;
    front2->next=NULL;
    while (1)
    {
        scanf("%d",&type);
        switch(type)
        {
            case 0:
                exit(0);
                break;
            case 1:
                scanf("%d %f %d",&id,&price,&quantity);
                getchar();
                scanf("%c",&bs);
                p=(struct order*)malloc(sizeof(struct order));
                p->orderid=count++;
                printf("orderid: %04d\n",p->orderid);
                p->stock=id;
                p->price=price;
                p->quantity=quantity;
                p->type=bs;
                p->next=NULL;
                if (bs == 'b')
                {
                    if (front2!=rear2)
                    {
                        q=front2->next;
                        while (q!=NULL && p->quantity!=0)
                        {
                            if (p->stock==q->stock && p->price>=q->price && q->quantity!=0)
                            {
                                temprice=(p->price+q->price)/2;
                                temquantity=min(p->quantity,q->quantity);
                                p->quantity-=temquantity;
                                q->quantity-=temquantity;

                                printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",temprice,temquantity,p->orderid,q->orderid);
                            }
                            q=q->next;
                        }
                        if (p->quantity!=0)
                        {
                            if (front1!=rear1)
                            {
                                q=front1->next;
                                temp=front1;
                                while (q!=NULL)
                                {
                                    if (p->price<=q->price)
                                    {
                                        temp=q;
                                        q=q->next;
                                        if (q==NULL)
                                        {
                                            temp->next=p;
                                        }
                                        continue;
                                    }
                                    else
                                    {
                                        p->next=q;
                                        temp->next=p;
                                        break;
                                    }
                                    if (q->next==NULL)
                                    {
                                        q->next=p;
                                        p->next=NULL;
                                        rear1=p;
                                    }
                                }
                            }
                            else
                            {
                                front1->next=rear1=p;
                            }
                        }
                        else
                        {
                            free(p);
                        }

                    }
                    else
                    {
                        if (front1!=rear1)
                        {
                            q=front1->next;
                            temp=front1;
                            while (q!=NULL)
                            {
                                if (p->price<=q->price)
                                {
                                    temp=q;
                                    q=q->next;
                                    if (q==NULL)
                                    {
                                        temp->next=p;
                                    }
                                    continue;
                                }
                                else
                                {
                                    p->next=q;
                                    temp->next=p;
                                    break;
                                }
                                if (q->next==NULL)
                                {
                                    q->next=p;
                                    p->next=NULL;
                                    rear1=p;
                                }
                            }
                        }
                        else
                        {
                            front1->next=rear1=p;
                        }
                    }
                }

                if (bs == 's')
                {
                    if (front1!=rear1)
                    {
                        q=front1->next;
                        while (q!=NULL && q->quantity!=0)
                        {
                            if (p->stock==q->stock && p->price<=q->price && p->quantity!=0)
                            {
                                temprice=(p->price+q->price)/2;
                                temquantity=min(p->quantity,q->quantity);
                                p->quantity-=temquantity;
                                q->quantity-=temquantity;

                                printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",temprice,temquantity,p->orderid,q->orderid);
                            }
                            q=q->next;
                        }
                        if (p->quantity!=0)
                        {
                            if (front2!=rear2)
                            {
                                q=front2->next;
                                temp=front2;
                                while (q!=NULL)
                                {
                                    if (p->price>=q->price)
                                    {
                                        temp=q;
                                        q=q->next;
                                        if (q==NULL)
                                        {
                                            temp->next=p;
                                        }
                                        continue;
                                    }
                                    else
                                    {
                                        p->next=q;
                                        temp->next=p;
                                        break;
                                    }
                                    if (q->next==NULL)
                                    {
                                        q->next=p;
                                        p->next=NULL;
                                        rear2=p;
                                    }
                                }
                            }
                            else
                            {
                                front2->next=rear2=p;
                            }
                        }
                        else
                        {
                            free(p);
                        }
                    }
                    else
                    {
                        if (front2!=rear2)
                        {
                            q=front2->next;
                            temp=front2;
                            while (q!=NULL)
                            {
                                if (p->price>=q->price)
                                {
                                    temp=q;
                                    q=q->next;
                                    if (q==NULL)
                                    {
                                        temp->next=p;
                                    }
                                    continue;
                                }
                                else
                                {
                                    p->next=q;
                                    temp->next=p;
                                    break;
                                }
                                if (q->next==NULL)
                                {
                                    q->next=p;
                                    p->next=NULL;
                                    rear2=p;
                                }
                            }
                        }
                        else
                        {
                            front2->next=rear2=p;
                        }


                    }




                }
                break;
            case 2:
                scanf("%d",&id);
                printf("buy orders:\n");
                p=front1->next;
                while (p!=NULL)
                {
                    if (p->stock == id && p->quantity!=0)
                    {
                        printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderid,p->stock,p->price,p->quantity,p->type);
                    }
                    p=p->next;
                }
                printf("sell orders:\n");
                p=front2->next;
                while (p!=NULL)
                {
                    if (p->stock == id && p->quantity!=0)
                    {
                        printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderid,p->stock,p->price,p->quantity,p->type);
                    }
                    p=p->next;
                }
                break;
            case 3:
                scanf("%d",&id);
                temp=front1;
                p=front1->next;
                while (p!=NULL)
                {
                    if (p->orderid==id)
                    {
                        temp->next=p->next;

                        flag=1;
                        printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderid,p->stock,p->price,p->quantity,p->type);
                        free(p);
                        break;
                    }
                    temp=p;
                    p=p->next;
                }
                temp=front2;
                p=front2->next;
                while (p!=NULL && !flag)
                {
                    if (p->orderid==id)
                    {
                        temp->next=p->next;
                        flag=1;
                        printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderid,p->stock,p->price,p->quantity,p->type);
                        free(p);
                        break;
                    }
                    temp=p;
                    p=p->next;
                }
                if (flag == 0)
                {
                    printf("not found\n");
                }
                flag=0;
                break;
        }
    }
}
