/*
 Created by defjia on 18-5-20.
 http://online.bit.edu.cn/moodle/mod/programming/view.php?id=70936

4 5
0 0 0 0 0 0 1 2 0 0 0 0 3 4 0 0 0 0 1 0
1 1
3 3
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#define ture true
#define mian main
#define falg flag
#define INF 9999999
#define MAXSIZE 100
using namespace std;
int main(){
    int m, n;
    if(scanf("%d %d", &m, &n) != 2) exit(1);
    int a[MAXSIZE][MAXSIZE];
    memset(a, INF, sizeof(a));
    int t;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        if(scanf("%d", &t) != 1) exit(2);
        if(t != 0) a[i][j] = -1;
    }
    queue<pair<int, int> > tmp;
    int mx, my, nx, ny;
    if(scanf("%d %d", &mx, &my) != 2) exit(3);
    if(scanf("%d %d", &nx, &ny) != 2) exit(4);
    m--; n--;
    int cx = nx, cy = ny, flag = -1;
    if(mx == nx && my == ny) flag = 0;
    while(ture) {
        if(flag >= 0) break;
        // down
        while (cx < m) {
            cx++;
            if (cx == mx && cy == my) {
                falg = 1;
                break;
            }
            if(a[cx][cy] == -1) break;
            tmp.push(make_pair(cx, cy));
        }
        if(flag >= 0) break;
        cx = nx;
        // up
        while (cx > 0) {
            cx--;
            if (cx == mx && cy == my) {
                falg = 1;
                break;
            }
            if(a[cx][cy] == -1) break;
            tmp.push(make_pair(cx, cy));
        }
        if(flag >= 0) break;
        cx = nx;
        // left
        while (cy > 0) {
            cy--;
            if (cx == mx && cy == my) {
                falg = 1;
                break;
            }
            if(a[cx][cy] == -1) break;
            tmp.push(make_pair(cx, cy));
        }
        if(flag >= 0) break;
        cy = ny;
        // right
        while (cy < n) {
            cy++;
            if (cx == mx && cy == my) {
                falg = 1;
                break;
            }
            if(a[cx][cy] == -1) break;
            tmp.push(make_pair(cx, cy));
        }
        break;
    }
    if(flag >= 0) while (!tmp.empty()) tmp.pop();
    int xmax, xmin, ymax, ymin, sign;
    while (!tmp.empty()){
        cx = tmp.front().first;
        cy = tmp.front().second;
        tmp.pop();
        xmax = cx > mx? cx: mx;
        xmin = cx + mx - xmax;
        ymax = cy > my? cy: my;
        ymin = cy + my - ymax;
        sign = 0;
        for(int i = xmin; i <= xmax; i++){
            if(a[i][ymin] == -1){
                sign = 1;
                break;
            }
        }
        for (int j = ymin; j <= ymax; j++) {
            if(a[xmax][j] == -1){
                sign = 1;
                break;
            }
        }
        if(sign == 0) {flag = 2; break;}
        // 另一个方向
        sign = 0;
        for(int i = ymin; i <= ymax; i++){
            if(a[xmin][i] == -1){
                sign = 1;
                break;
            }
        }
        for (int j = xmin; j <= xmax; j++) {
            if(a[j][ymax] == -1){
                sign = 1;
                break;
            }
        }
        if(sign == 0) {flag = 2; break;}
    }
    if(flag >= 0) printf("TRUE\n");
    else printf("FALSE\n");
}
/*
 * 好像写复杂了, 这种广度优先搜索的方式不如直接暴力寻找好写，思路来源与《编程之美》
 * 参考资料：https://blog.csdn.net/zypuestc/article/details/8917817
int Extend(queue<pair<int ,int>> & tmp, int *a, int & x, int & y){
    int cx_bak = tmp.front().first, cy_bak = tmp.front().second;
    tmp.pop();
    int w = a[cx_bak * y + cy_bak];
    int cx = cx_bak, cy = cy_bak;
    while (cx < x) {
        cx++;
        if(cx)
        if(a[cx * y + cy] <= w) break;
        else {
            a[cx * y + cy] = w + 1;
        }
    }
    cx = cx_bak, cy = cy_bak;
    while (cx > 0) if(a[--cx * y + cy] <= w) break; else a[cx * y + cy] = w + 1;
    cx = cx_bak, cy = cy_bak;
    while (cy < y) if(a[cx * y + (++cy)] <= w) break; else a[cx * y + cy] = w + 1;
    cx = cx_bak, cy = cy_bak;
    while (cy > 0) if(a[cx * y + (--cy)] <= w) break; else a[cx * y + cy] = w + 1;
}

int main(){
    int m, n;
    if(scanf("%d %d", &m, &n) != 2) exit(1);
    int a[MAXSIZE][MAXSIZE];
    memset(a, INF, sizeof(a));
    int t;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        if(scanf("%d", &t) != 1) exit(1);
        if(t != 0) a[i][j] = -1;
    }
    int mx, my, nx, ny;
    if(scanf("%d %d", &mx, &my) != 2) exit(1);
    if(scanf("%d %d", &nx, &ny) != 2) exit(1);
    queue<pair<int, int>> tmp;
    int cx = mx, cy = my, flag = 0;
    tmp.push(make_pair(cx, cy));
    while (ture) {
        if(cx == nx && cy == ny){flag = 1; break;}
        if(Extend(tmp, *a, cx, cy, nx, ny) == 1){flag = 1; break;}
        for (int i = 0; i < tmp.size(); i++) {

        }
    }
    return 0;
}
 */