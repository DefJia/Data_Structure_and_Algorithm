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
    for(i = len; i > 1; i--){
        swap(arr[i], arr[1]);
        max_heapify(arr, 1, i-1);
    }
}

int main(){
    int n, tmp, hh[MAXSIZE], i = 1, j;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &tmp);
        hh[i++] = tmp;
    }
    heap_sort(hh, i-1);
    for(j = i-1; j > 0; j--) cout << hh[j] << ' ';
    cout << "\n";
    heap_sort(hh, i-2);
    for(j = i-2; j > 0; j--) cout << hh[j] << ' ';
    cout << "\n";
    heap_sort(hh, i-3);
    for(j = i-3; j > 0; j--) cout << hh[j] << ' ';
    cout << "\n";
    return 0;
}