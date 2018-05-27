//
// Created by defjia on 18-5-14.
//http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68472
//
#include  <algorithm>
#include <iostream>
#define MAXSIZE 100000
using namespace std;
// index of arr starts from 1.
void max_heapify(int *arr, int start, int end){
    int dad = start;
    int son = dad * 2;
    // son2 = dad * 2 + 1;
    while (son <= end){
        if(son != end && arr[son] < arr[son+1]) son++;
        // Choose the biggest one in two sons
        if(arr[dad] > arr[son]) return;
            // Finish.
        else{
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2;
            // loop again.
        }
    }
}

void heap_sort(int *arr, int len){
    int i;
    for(i = len / 2; i > 0; i--){
        max_heapify(arr, i, len);
    }// Initialization
            /*
    for(i = len; i > 1; i--){
        swap(arr[i], arr[1]);
        max_heapify(arr, 1, i-1);
    }
             */
}
int add_elem(int *arr, int len, int elem){
    arr[++len] = elem;
    int son = len, dad = len / 2;
    while (dad >= 1 && arr[son] > arr[dad]){
        swap(arr[son], arr[dad]);
        if(dad == 1) break;
        son = dad;
        dad = son / 2;
    }
    return len;
}
int rm_top(int *arr, int len){
    int i = 1;
    while (2 * i < len){
        if(2 * i > 2 * i + 1){
            arr[i] = arr[2 * i];
            i = 2 * i;
        } else{
            arr[i] = arr[2 * i + 1];
            i = 2 * i + 1;
        }
    }
    return --len;
}
void output(int *arr, int len){
    for(int i = 1; i <= len; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main(){
// #define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int n, tmp, hh[MAXSIZE], i = 1, len = 0, j;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &tmp);
        hh[i++] = tmp;
    }
    len = i-1;
    heap_sort(hh, len);
    output(hh, len);
    hh[1] = hh[len--];
    heap_sort(hh, len);
    output(hh, len);
    hh[1] = hh[len--];
    heap_sort(hh, len);
    output(hh, len);
    return 0;
}