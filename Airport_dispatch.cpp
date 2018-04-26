//
// Created by defjia on 18-4-22.
//
#include <cstdlib>
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
    int busy_time = 0, remain_time = 0;
}Runway;
typedef struct {
    int total = 0, num, wait_time = 0;
}Count;
int main(){
    int runway_num, land_time, takeoff_time, time = 0;
    int land_num, takeoff_num;
    Count land, takeoff; land.num = 5001; takeoff.num = 1;
    Runway arr[100]; int cur = 0;
    queue<int> land_queue, takeoff_queue;
    int flag = 0, flag2 = 0;
    if(scanf("%d%d%d", &runway_num, &land_time, &takeoff_time) != 3)exit(1);
    printf("Current Time: %4d\n", time++);
    if(scanf("%d%d", &land_num, &takeoff_num) != 2) exit(1);
    while (land_num >= 0 && takeoff_num >= 0){
        land.total += land_num; takeoff.total += takeoff_num;
        while(land_num-- > 0) land_queue.push(land.num++);
        while(takeoff_num-- > 0) takeoff_queue.push(takeoff.num++);
        cur = 0;
        while (!land_queue.empty()){
            while (!arr[cur++].remain_time){
                arr[cur - 1].remain_time = land_time;
                printf("airplane %04d is ready to land on runway %02d\n", land_queue.front(), cur);
                land_queue.pop();
                if(land_queue.empty() || cur == runway_num) break;
            }
            if(land_queue.empty() || cur == runway_num) break;
        }
        cur = 0;
        while (!takeoff_queue.empty()){
            while (!arr[cur++].remain_time){
                arr[cur-1].remain_time = takeoff_time;
                printf("airplane %04d is ready to takeoff on runway %02d\n", takeoff_queue.front(), cur);
                takeoff_queue.pop();
                if(takeoff_queue.empty() || cur == runway_num) break;
            }
            if(takeoff_queue.empty() || cur == runway_num) break;
        }

        printf("Current Time: %4d\n", time++);
        for(cur = 0; cur < runway_num; cur++){
            if (arr[cur].remain_time == 1) printf("runway %02d is free\n", cur+1);
            if (arr[cur].remain_time > 0) {
                arr[cur].busy_time++;
                arr[cur].remain_time--;
            }
        }
        land.wait_time += land_queue.size();
        takeoff.wait_time += takeoff_queue.size();
        if (land_queue.empty() && takeoff_queue.empty()){
            flag2 = 0;
            for(cur = 0; cur < runway_num; cur++) if(arr[cur].remain_time != 0) flag2++;
            if(flag2 == 0 && flag == 1) break;
        }
        if (flag == 0){
            if(scanf("%d%d", &land_num, &takeoff_num) != 2) exit(1);
            if(land_num == -1) flag = 1;
        }
        if (flag == 1 || land_num == -1){
            land_num = 0; takeoff_num = 0;
        }
    }
    printf("simulation finished\n");
    printf("simulation time: %4d\n", time-1);
    if(land.total != 0) printf("average waiting time of landing: %4.1f\n", (double)land.wait_time / land.total);
    else printf("average waiting time of landing: %4.1f\n", (double)land.wait_time );
    if(takeoff.total != 0) printf("average waiting time of takeoff: %4.1f\n", (double)takeoff.wait_time / takeoff.total);
    else printf("average waiting time of takeoff: %4.1f\n", (double)takeoff.wait_time );
    int sum = 0;
    for (cur = 0; cur < runway_num; cur++) {
        printf("runway %02d busy time: %4d\n", cur + 1, arr[cur].busy_time);
        sum += arr[cur].busy_time;
    }
    if (time-1 != 0) printf("runway average busy time percentage: %4.1f%%\n", (double)sum * 100 / (time-1)/ runway_num);
    else printf("runway average busy time percentage: %4.1f%%\n", (double)sum);
    return 0;
}
