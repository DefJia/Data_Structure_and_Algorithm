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

int main(){ 
 Stack test; 
    InitStack(test); 
    Push(test, 1); 
    Push(test, 2); 
    Push(test, 3); 
    ELEM e; 
    Pop(test); 
  printf("%d\n", e); 
}