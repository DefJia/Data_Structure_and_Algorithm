#include <stdio.h> 
#include <cstdlib> 
#include <stdlib.h> 
#include <string.h>
#define INIT_SIZE 1
#define INCREMENT 1 
 
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
 
 
int isLet(char c){ 
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0'&&c<='9'); 
} 
 
/* 
int main(){ 
 Stack test; 
    InitStack(test); 
   Push(test, 1); 
 Push(test, 2); 
 Push(test, 3); 
 ELEM e; 
    Pop(test, e); 
  printf("%d\n", e); 
}*/ 
//Add my personal understanding of precedence relationships of operators to replace the <<<<<>>>>><><<><><>. 
int convert(char z){ 
  int v = 9999; 
  switch (z){ 
        //一级运算符 
        case '+': v = 1; break; 
        case '-': v = 1; break; 
        //二级运算符 
        case '*': v = 2; break; 
        case '/': v = 2; break; 
        //case '%': v = 2; break; 
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
//以上两个函数为了寻找运算符冥冥之中的数学联系，没有任何实际意义 
/*测试 
int main(){ 
 char arr[] = {'+', '-', '*', '/', '(', ')', '#'}; 
  for (int i = 0; i < 7; i++){ 
        for (int j = 0; j < 7; j++){ 
            int c = judge(arr[i], arr[j]); 
         printf("%2d ", c); 
     } 
      printf("\n"); 
  } 
} 
*/ 
/*
void pre_main(){ 
    Stack optr, opnd; 
  char c; 
    InitStack(optr); 
   Push(optr, '#'); 
   InitStack(opnd); 
   c = getchar(); 
 while(c != '#' || GetTop(optr) != '#'){ 
        if (isLet(c)){ 
         	Push(opnd, c); 
         	printf("%c",Pop(opnd)); 
            c = getchar(); 
     	}else{ 
         	if(optr.top != optr.base){ 
             switch(judge(GetTop(optr), c)){ 
                    case 1: 
                        printf("%c", Pop(optr)); 
                       break; 
                 case 0: 
                        Pop(optr); 
                     c = getchar(); 
                     break; 
                 case -1: 
                       Push(optr, c); 
                     c = getchar(); 
                     break; 
                 case -2: 
                       printf("Wrong input.\n"); 
                      //printf("%c\n", GetTop(optr)); 
                        //printf("%c\n", c); 
                       return; 
                        //break; 
               } 
          }else{ 
             Push(optr, c); 
         } 
      } 
  } 
  printf("\n"); 
  return; 
} 
*/

int main(){
  int times;
 scanf("%d", &times);
 while(times--){
  char ext[200];
  Stack optr;
  InitStack(optr);
  memset(ext, 0, sizeof(ext));
  scanf("%s", ext+1);
  ext[0] = '#';
  Push(optr, '#');
  int i = 1;
  while(ext[i] != '#' || GetTop(optr) != '#'){
    if(isLet(ext[i])){
      putchar(ext[i++]);
    } else{
      if(optr.top != optr.base){
        switch(judge(GetTop(optr), ext[i])){
          case 1:
            printf("%c", Pop(optr)); 
            break;
          case 0:
            Pop(optr);
            i++;
            break;
          case -1:
            Push(optr, ext[i++]);
            break;
          case -2:
            printf("Wrong Input;\n");
            break;
        }
      }
    }
  }
  printf("\n");
 }
  return 0;
}

/*
int main(){ 
 int n; 
 scanf("%d", &n);
 if(n == 0){return 0;} 
 for(int i = 0; i < n; i++){ 
        pre_main(); 
        char a; 
        scanf("%c", &a); 
   } 
}  
*/

