#include <stack>
using  namespace std;
int partition(int *a, int left, int right) {
    if (a == nullptr || left < 0 || right <= 0||left>=right)
        return -1;
    int pivot = a[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i > j&&a[j] >= pivot)
            j--;
        if(i<j)
            a[i]=a[j];
        while (i < j&&a[i] <= pivot)
            i++;
        if(i<j)
            a[j]=a[i];
    }
    a[i] = pivot;
    return i;
}

void QuickSort(int *a, int left,int right) {
    if (a == nullptr || left < 0 || right <= 0 || left>right) return;
    stack<int>temp;
    int i, j;
    temp.push(right);
    temp.push(left);
    while (!temp.empty()) {
        i = temp.top(); temp.pop();
        j = temp.top(); temp.pop();
        if (i < j) {
            int k = partition(a, i, j);
            if (k > i) {
                temp.push(k - 1);
                temp.push(i);
            }
            if (j > k) {
                temp.push(j);
                temp.push(k + 1);
            }
        }
    }
}