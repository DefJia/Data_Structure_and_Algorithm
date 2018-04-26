#include <stack>
#include <map>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

int flag = 0;

int isNum(char c){
    return (c>='0'&&c<='9');
}

int isLet(char c){
	return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
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

map<string, int> mymap;
string deVar(string exp){
	string tmp = "", var;
	for(int i = 0; i < exp.size(); i++){
		if(isLet(exp[i])){
			var = "";
			for(; isLet(exp[i+1]); i++){
				var += exp[i];
			}
			var += exp[i];
			tmp += to_string(mymap[var]);
		} else{
			tmp += exp[i];
		}
	}
	return tmp;
}

void cal(string line){
	string var = "", exp = "";
	int i = 1;
	for ( string::iterator it=line.begin(); *it!='='; ++it, ++i) var += *it;
	exp = line.substr(i);

	flag = 0;
	stack<int> opnd;
	stack<char> optr;
	optr.push('#');

	i = 1;
	int a, b, res;
	char op;
	int minus = 1;

	exp = deVar(exp);
	exp = "#" + exp + "#";

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
		mymap[var] = opnd.top();
	}//else if (flag == -1) 
}

int main(){
	string line;
	getline(cin, line);
	while(line.compare("end")){
		if(line[0] == '?'){
			string var = line.substr(2);
			cout << var+"="+to_string(mymap[var])+"\n";
		}else{
			cal(line);
		}
		getline(cin, line);
	}//行数循环
}

