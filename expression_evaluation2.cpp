#include <stack>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int isNum(char c){
    return (c>='0'&&c<='9');
}

int convert(char z){
	int v = 9999;
	switch (z){
		//一级运算符
		case '+': v = 1; break;
		case '-': v = 1; break;
		//二级运算符
		case '*': v = 2; break;
		case '/': v = 2; break;
		case '%': v = 2; break;
		//三级运算符
		case '^': v = 4; break;
		//一般弱
		case '(': v = -1000; break;
		//一般强
		case ')': v = 1000; break;
		//前弱后强
		case '#': v = 500; break;
	}
	return v;
}

int judge(char a, char b){
	int q = convert(a);if(q==500)q-=1000;
	int p = convert(b);
	int flag1 = q - p;
	int flag2 = q + p;
	int flag3 = abs(q) + abs(p);
	if (flag3 < 10){
	//仅有基本运算符
		if (flag1 < 0 || flag3 == 8) return -1;
		//a^b^c要转为abc^^
		else return 1;
	}else if (abs(abs(flag3) - 1000) < 10 || abs(abs(flag3) - 2000) < 10){
	//括号与基本操作符
		if (flag2 < 0) return -1;
		else if (flag2 > 0) return 1;
		else if (flag2 == 0 && flag1 != 2000) return 0;
		else return -2;
	}else if (flag3 == 1500 && flag1 == 500){
	//# vs ><
		if (flag2 < 0) return -1;
		else return 1;
	}else if (abs(abs(flag3) - 500) < 10){
	//#与基本操作符
		if (abs(flag1) < 500) return 1;
		if (abs(flag1) > 500) return -1;
	}else {
		return -2;
	}
	return -2;
}

int flag = 0;
int operate(int a, char op, int b){
	int res = 0;
	switch(op){
		case '+':{ res = a + b;	break;}
		case '-':{ res = a - b;	break;}
		case '*':{ res = a * b; break;}
		case '/':{
			if(b == 0){
				flag = -1;
				break;
			}
			res = a / b;
			break;
		}
		case '%':{
			if(b == 0){
				flag = -1;
				break;
			}
			res = a % b;
			break;
		}
		case '^':{
			if(b < 0) flag = -2;
			res = pow(a, b);
			break;
		}
		default:{
			flag = -3;
			break;
		}
	}
	return res;
}

int main(){
	int times;
	if(scanf("%d", &times)!=1)exit(0);
	while(times--){
		flag = 0;
		stack<int> opnd;
		stack<char> optr;
		optr.push('#');

		int i = 1;
		int a, b, res;
		char op;
		int minus = 1;

		char exp[200];
		memset(exp, '0', sizeof(exp));
		if(scanf("%s", exp+1)!=1)exit(0);
		exp[0] = '#';
		exp[strlen(exp)] = '#';

		while(exp[i] != '#' || optr.top() != '#'){
			if(isNum(exp[i])){
				int num = exp[i] - '0';
				int ti = 1;
				while(isNum(exp[i+ti])){
					num = num * 10 + (exp[i+(ti++)] - '0');
				}
				num *= minus;
				minus = 1;
				opnd.push(num);
				i += ti;
			}else if(exp[i] == '-' && isNum(exp[i+1]) && (!isNum(exp[i-1]) || !exp[i-1] == ')')){
					minus = -1;
					i++;
			}else if(exp[i] == '(' && !(isNum(exp[i+1]) || exp[i+1] == '-' || exp[i+1] == '#' || exp[i+1] == '(')){
				flag = -6;
			}else{
				switch(judge(optr.top(), exp[i])){
					case -1:{
						optr.push(exp[i++]);
						break;
					}case 0:{
						optr.pop();
						i++;
						break;
					}case 1:{
						if(!opnd.empty()) {a = opnd.top(); opnd.pop();}
						else {flag = -5; break;}
						if(!opnd.empty()) {b = opnd.top(); opnd.pop();}
						else {flag = -5; break;}
						op = optr.top();
						optr.pop();
						res = operate(b, op, a);
						if (flag < 0) break;
						opnd.push(res);
						break;
					}case -2:{
						flag = -4;
						break;
					}
				}
			}
			if(flag < 0) break;
		}//字符循环
		if(flag < 0 || optr.size() != 1 || opnd.size() != 1){
			if(flag == -1) printf("Divide 0.\n");
			else printf("error.\n");
		}else if (flag == 0){
			printf("%d\n", opnd.top());
		}//else if (flag == -1) 
	}//次数循环
}