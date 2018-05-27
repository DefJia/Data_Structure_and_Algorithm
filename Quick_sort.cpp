//
// Created by defjia on 18-5-23.
// http://online.bit.edu.cn/moodle/mod/programming/view.php?id=70945
//
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>
#define ture true
#define mian main
#define falg flag
#define MAXSIZE 999999
using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int convert2(int a[], int right, int left){
    int q = a[right] - a[(int)(left+right)/2], p = a[right] - a[left];
    if(q * p > 0){
        if(abs(q) > abs(p)){
            swap(a[right], a[left]);
        } else{
            swap(a[right], a[(int)(left+right)/2]);
        }
    }
    return a[right];
}
int convert(int numVector[], int Left, int Right){
    int Middle = (Left + Right) / 2;
    if (numVector[Left] > numVector[Middle])
        swap(numVector[Left], numVector[Middle]);
    if (numVector[Left] > numVector[Right])
        swap(numVector[Left], numVector[Right]);
    if (numVector[Middle] > numVector[Right])
        swap(numVector[Middle], numVector[Right]);
    swap(numVector[Middle], numVector[Left]);
    return numVector[Left];
}
void sort(int a[], int left, int right, queue<int> &qaq){
    if(a == nullptr || left < 0 || right <= 0 || left >= right) return ;
    if(left < right) {
        int pivot = convert(a, left, right);
        // int pivot = convert2(a, left, right);
        if(right - left >= 5) qaq.push(pivot);
        // for(int k = 0; k < 15; k++) printf("%d ", a[k]); printf("-%d-\n", a[left]);
        int i = left, j = right+1;
        while (i < j) {
            do i++; while (a[i] < pivot);
            do j--; while (a[j] > pivot);
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[left], a[j]);
        // for(int k = 0; k < 15; k++) printf("%d ", a[k]); printf("-%d-\n", a[j]);
        sort(a, left, j - 1, qaq);
        sort(a, j + 1, right, qaq);
    }
}
int main(){
// #define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
    freopen("../Create_use_cases/data.out.txt","w",stdout);
#endif
    int a[MAXSIZE], b, i = 0;
    queue<int> median3;
    while (scanf("%d", &b)) a[i++] = b;
    // Construction
    sort(a, 0, i-1, median3);
    printf("After Sorting:\n");
    for(int j = 0; j < i; j++) printf("%d ", a[j]);
    printf("\nMedian3 Value:\n");
    if(median3.empty()) printf("none");
    else {
        while (!median3.empty()){
            printf("%d ", median3.front());
            median3.pop();
        }
    }
    printf("\n");
}

