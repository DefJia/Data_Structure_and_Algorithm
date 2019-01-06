#include<stdio.h>
#define N 305
int main()
{
    int a[N][N];
    int i,j,k,n;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(k=0;k<n;k++)
            for(j=0;j<n;j++){
                if((a[i][k]!=0)&&(a[k][j]!=0))
                    a[i][j]=1;
            }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if((a[i][j]==0)&&(a[j][i]==0)){
                printf("3\n");return 0;}
            if(a[i][j]+a[j][i]==1){
                printf("2\n");return 0;}
        }
    printf("1\n");
}
