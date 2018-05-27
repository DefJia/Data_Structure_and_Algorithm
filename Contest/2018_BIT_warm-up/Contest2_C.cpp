//
// Created by defjia on 18-5-12.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXSIZE 1000
int main(){
    int n, q, p;
    scanf("%d", &n);
    while (n--){
        int nn, flag = 0;
        scanf("%d", &nn);
        int nni = nn, nnii = nn;
        int tmp[MAXSIZE][2], i = 0, record[MAXSIZE];
        memset(tmp, 0, MAXSIZE);
        while(nni--){
            if(n == 0 && nni == 0)
                scanf("%d %d", &q, &p);
            else
                scanf("%d %d\n", &q, &p);
            tmp[i][0] = q;
            tmp[i++][1] = p - q + 1;
        }
        int time = 1, j = 0;
        while(nn){
            for(int z = 0; z < nnii; z++) {
                if (tmp[z][1] >= 0 && tmp[z][0] <= time) {
                    tmp[z][1] = -1;
                    record[z] = time;
                    nn--;
                    break;
                }
            }
            // del over time
            for(int z = 0; z < nnii; z++){
                if(tmp[z][0] <= time && tmp[z][1] != -1){
                    tmp[z][1]--;
                    if(tmp[z][1] == 0){
                        record[z] = 0;
                        tmp[z][1] = -1;
                        nn--;
                    }
                }
            }
            time++;
        }
        for (i = 0; i < nnii; i++){
            printf("%d", record[i]);
            if(i < nnii-1) printf(" ");
        }
        printf("\n");
    }
}