#include <stdio.h>
#include <cstdlib>
#include <stack>
using namespace std;
int cmp(int a, int b){
    if(a == b)return 0;
    if(a < b)return -1;
    if(a > b)return 1;
}
int main(){
	int group, times, flag, num, q, k = 0;
	scanf("%d%d", &group, &times);
	while(!(group == 0 && times == 0)){
		if(k++) printf("\n");
		while(times--){
			stack<int> Stack;
			Stack.push(0);
			flag = 0;
			q = 0;
			for(int i = 0; i < group; i++){
				scanf("%d", &num);
				if(!flag){
					switch(cmp(num, Stack.top())){
						case 1:{for(q++; q < num; q++) Stack.push(q); break;}
						case 0:{Stack.pop(); break;}
						case -1: {flag = -1; break;}
					}
				}
			}
			if(flag == -1) printf("No\n");
			else printf("Yes\n");
		}//行循环
		scanf("%d%d", &group, &times);
	}//组循环
}
