#include<math.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#define INIT_SIZE 100
#define INCREMENT 10

typedef char ELEM;

typedef struct{
	ELEM *top;
	ELEM *base;
	int size;
}Stack;

void InitStack(Stack &S){
	S.base = (ELEM *)malloc(INIT_SIZE * sizeof(ELEM));
	if(!S.base){exit(0);}
	S.top = S.base;
	S.size = INIT_SIZE;
}

char GetTop(Stack &S){
	if(S.top == S.base){
		printf("stack is empty!\n");
		return '?';
	}
	char e = *(S.top - 1);
	return e;
}

void Push(Stack &S, ELEM e){
	if(S.top - S.base >= S.size){
		S.base = (ELEM *)realloc(S.base, (S.size + INCREMENT) * sizeof(ELEM));
		if(!S.base)exit(0);
		S.top = S.base + S.size;//deletable
		S.size += INCREMENT;
	}
	*S.top++ = e;//指针加减
}

char Pop(Stack &S){
	if(S.top == S.base)return '?';
	ELEM e;
	e = *--S.top;
	return e;
	//printf("%c", e);
}


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
				printf("Divide 0.\n");
				break;
			}
			res = a / b;
			break;
		}
		case '%':{
			if(b == 0){
				flag = -1;
				printf("Divide 0.\n");
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
	char exp[200];
	int times;
	if(scanf("%d", &times)!=1)exit(0);
	while(times--){
		int i = 0;
		Stack optr, opnd;
		int a, b, res;
		char op;

		memset(exp, '0', sizeof(exp));
		scanf("%s", exp);
		exp[strlen(exp)] = '#';

		InitStack(optr);
		Push(optr, '#');
		InitStack(opnd);

		while(exp[i] != '#' || GetTop(optr) != '#'){
			flag = 0;
			if (isNum(exp[i])){
				Push(opnd, exp[i++]);
			}else{
				//if(optr.top != optr.base){
					switch(judge(GetTop(optr), exp[i])){
						case 1:
							a = Pop(opnd) - '0';
							b = Pop(opnd) - '0';
							op = Pop(optr);
							res = operate(b, op, a);
							if (flag != 0) break;
							Push(opnd, res);
							break;
						case 0:
							Pop(optr);
							i++;
							break;
						case -1:
							Push(optr, exp[i++]);
							break;
						case -2:
							flag = -4;
							printf("error1.\n");
							break;
					}
				//}else{
				//	Push(optr, c);
				//}
			}
			if(flag != 0)break;
		}
		if (!flag){
			res = GetTop(opnd);
			if(opnd.top == opnd.base || GetTop(optr) != '#')printf("error2.\n");
			else printf("%d\n", res);
		}
	}
	return 0;
}
