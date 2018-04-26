#include <stdio.h>
#include <cstdlib>
int main(){
	int n, m, wpl = 0;
	int arr[10000];
	if(scanf("%d", &n) != 1)exit(0);
	for(int i = 0; i < n; i++){
		if(scanf("%d", & m) != 1)exit(0);
		arr[i] = m;
	}
	for(int i = 1; i < n; i++){
		int min1 = -1, min2 = -1;
		for (m = 0; m < n; m++){
			if(arr[m] != 0){
				if(min1 == -1) min1 = m;
				else if (min2 == -1){
					if (arr[m] < arr[min1]){min2 = min1;min1 = m;} 
					else {min2 = m;}
				}else {
					if(arr[m] < arr[min1]){min2 = min1;min1 = m; }
					else if (arr[m] < arr[min2]){min2 = m; }
				}
			}
		}//找最小
		if(min2 != -1){
			arr[min1] += arr[min2];
			wpl += arr[min1];
			arr[min2] = 0;
		}
	}//合并
	printf("WPL=%d\n", wpl);
	return 0;
}