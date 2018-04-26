#include <stdio.h>
#include <stdlib.h>

struct airline
{
    int id;
    int wtime;
    int busytime;
    struct airline *next;
};

struct air
{
    int id;
    int type;
    int wtime;
    struct air *next;
};

int main(){
    int n,time=0,landtime,taketime,landnum,takenum,airlineid=1,landid=5001,takeid=1,i,j,k,or1=1,or2=1,flag;
    float wland=0,wtake=0,plane1=0,plane2=0,sum=0,time1,n1;
    struct airline *lhead=NULL,*lp,*lq;
    struct air *ahead1=NULL,*arear1,*ap1,*aq1,*asearch1,*ahead2=NULL,*arear2,*ap2,*aq2,*asearch2;

    scanf("%d %d %d",&n,&landtime,&taketime);
    for (i=0;i<n;i++)
    {
        lp=(struct airline*)malloc(sizeof(struct airline));
        lp->busytime=0;
        lp->id=airlineid++;
        lp->wtime=0;
        lp->next=NULL;
        if (lhead==NULL) lhead=lq=lp;
        else
        {
            lq->next=lp;
            lq=lp;
        }

    }

    while(1)
    {
        printf("Current Time: %4d\n",time++);

        lp=lhead;
        while (lp!=NULL)
        {
            if (lp->wtime!=0)
            {
                lp->wtime--;
                if (lp->wtime==0)
                {
                    printf("runway %02d is free\n",lp->id);
                }
            }
            lp=lp->next;
        }

        if (or1>=0 && or2>=0)
        {
            scanf("%d %d",&landnum,&takenum);
            or1=landnum;
            or2=takenum;
            plane1+=landnum;
            plane2+=takenum;
        }

        for (i=0;i<landnum;i++)
        {
            ap1=(struct air*)malloc(sizeof(struct air));
            ap1->id=landid++;
            ap1->type=1;
            ap1->next=NULL;
            if (ahead1 == NULL)
            {
                ahead1=arear1=ap1;
            }
            else
            {
                arear1->next=ap1;
                arear1=ap1;
            }
        }
        for (i=0;i<takenum;i++)
        {
            ap2=(struct air*)malloc(sizeof(struct air));
            ap2->id=takeid++;
            ap2->type=2;
            ap2->next=NULL;
            if (ahead2 == NULL)
            {
                ahead2=arear2=ap2;
            }
            else
            {
                arear2->next=ap2;
                arear2=ap2;
            }
        }

        aq1=asearch1=ahead1;
        aq2=asearch2=ahead2;
        while (asearch1!=NULL)
        {
            lq=lhead;
            flag=0;
            while (lq!=NULL)
            {
                if (lq->wtime == 0)
                {
                    flag=1;
                    printf("airplane %04d is ready to land on runway %02d\n",asearch1->id,lq->id);
                    lq->wtime=landtime;
                    lq->busytime+=landtime;
                    if (ahead1->next!=NULL)
                        ahead1=ahead1->next;
                    else ahead1=NULL;
                    break;
                }
                lq=lq->next;
            }
            if (flag == 0)
            {
                wland++;
            }
            asearch1=asearch1->next;
        }

        while (asearch2!=NULL)
        {
            lq=lhead;
            flag=0;
            while (lq!=NULL)
            {
                if (lq->wtime == 0)
                {
                    flag=1;
                    printf("airplane %04d is ready to takeoff on runway %02d\n",asearch2->id,lq->id);
                    lq->wtime=taketime;
                    lq->busytime+=taketime;
                    if (ahead2->next!=NULL)
                        ahead2=ahead2->next;
                    else ahead2=NULL;
                    break;
                }
                lq=lq->next;
            }
            if (flag == 0)
            {
                wtake++;
            }
            asearch2=asearch2->next;
        }

        flag=0;
        lp=lhead;
        while (lp!=NULL)
        {
            if (lp->wtime==0)
            {
                flag++;
            }
            else break;
            lp=lp->next;
        }

        if (ahead1==NULL &&ahead2==NULL && flag==n && or1==-1 && or2==-1)
        {
            break;
        }

    }
    time1=time;
    n1=n;
    printf("simulation finished\n");
    printf("simulation time: %4d\n",time-1);
    printf("average waiting time of landing: %4.1f\n",(float)(wland/(plane1+1)));
    printf("average waiting time of takeoff: %4.1f\n",(float)(wtake/(plane2+1)));
    lq=lhead;
    while (lq!=NULL)
    {
        printf("runway %02d busy time: %4d\n",lq->id,lq->busytime);
        sum+=lq->busytime;
        lq=lq->next;
    }
    printf("runway average busy time percentage: %4.1f%%\n",sum/n1*100.0/(time1-1));

}  