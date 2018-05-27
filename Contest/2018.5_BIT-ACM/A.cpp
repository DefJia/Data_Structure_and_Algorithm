//
// Created by defjia on 18-5-24.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=72990
/*
1 1
1
5 10
1 2 3 4 5
*/
#include <bits/stdc++.h>
#define MAXSIZE 1000000
using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void quick_sort(int a[], int left, int right){
    if(a == nullptr || left< 0 || right <= 0 || left >= right) return;
    int i = left, j = right+1;
    int pivot = a[left];
    while (i < j){
        do i++; while (a[i] < pivot);
        do j--; while (a[j] > pivot);
        if(i < j) swap(a[i], a[j]);
    }
    swap(a[j], a[left]);
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right);
}
int main(){
    int n, s;
    while (scanf("%d %d", &n, &s) != EOF) {
        int a[MAXSIZE], n_bak = n, tmp;
        while (n_bak--){
            scanf("%d", &tmp);
            a[n-n_bak-1] = tmp;
        }
        quick_sort(a, 0, n-1);
        int flag = 0, i;
        for(i = 0; i < n-1; i++){
            s -= a[i];
            if(s <= 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("%d\n", n);
        else printf("%d\n", i);
    }
    return 0;
}
