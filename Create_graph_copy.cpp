#include <stdio.h>
#include<string.h>
int n=0,x,y;
struct {
    char nd[3];
    int bnum=0;
    int vsed =0;
    int linkto[100];
}node[100];
void search(int now){
    int temp[100],count=0;
    if(node[now].vsed==0){
        printf("%s",node[now].nd);
        node[now].vsed =1;
    }
    for(int i=node[now].bnum-1;i>=0;i--){
        if(node[node[now].linkto[i]].vsed==0){
            printf("%s",node[node[now].linkto[i]].nd);
            node[node[now].linkto[i]].vsed=1;
            temp[count]=node[now].linkto[i];
            count++;
        }

    }
    for(int i=0;i<count;i++)search(temp[i]);

}





int main() {

    while(1){
        scanf("%s",&node[n].nd);
        if(strcmp(node[n].nd,"*")==0){
            break;
        }
        n++;
    }
    while(1){
        scanf("%d,%d",&x,&y);
        if(x==-1)break;
        node[x].linkto[node[x].bnum] = y;
        node[x].bnum++;
        node[y].linkto[node[y].bnum] = x;
        node[y].bnum++;
    }

    printf("the ALGraph is\n");

    for(int i=0;i<n;i++){
        printf("%s",node[i].nd);
        for(int j=node[i].bnum-1;j>=0;j--){
            printf(" %d",node[i].linkto[j]);
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    for(int i=0;i<n;i++){
        if(node[i].vsed==0){
            search(i);
        }
    }
    printf("\n");
    return 0;
}
/*
作者：awlsx
        链接：https://www.jianshu.com/p/1433b6015184
        來源：简书
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/