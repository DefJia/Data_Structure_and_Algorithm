#include <stack>
#include <iostream>
#include <string>
using namespace std;
int cmp(int a, int b){
    if(a == b)return 0;
    if(a < b)return -1;
    if(a > b)return 1;
}
int main(){
	string line, order;
	int i, t;
	getline(cin, line);
	while (line != "0 0\n"&&line!="0 0\0" && line != ""){
		int total = line[0] - '0', times = line[2] - '0';
		while(times--){	
			getline(cin, order);
			int flag = 0, q = 0;
			// q 入栈指针
			stack<int> Stack;
			Stack.push(0);
			for(i = 0; i < total; i++){
				t = order[(2*i)] - '0';
				//cout<<t<<"@"<<Stack.top()<<"\n";
				switch(cmp(t, Stack.top())){
					case 1: {for(q++ ; q < t; q++) Stack.push(q); break;}
					case 0: {Stack.pop(); break;}
					case -1: {flag = -1; break;}
				}
				if(flag == -1) break;
			}
			if(flag == -1){cout << "No\n";}
			else {cout << "Yes\n";}
		}//行数
		getline(cin, line);
	}//组数
	return 0;
}
