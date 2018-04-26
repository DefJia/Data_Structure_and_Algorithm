#include <stdio.h>
#include <cstdlib>
#define MAXSIZE 50000
typedef struct node{
	struct node *left, *right;
	int z;
}Root;

int main(){
	long n, flag, num, i = 0;
	char d;
	Root *h = (node *)malloc(sizeof(node));
	Root *t, *cur;
	int data[MAXSIZE];
	if(!scanf("%c\n", &n)) exit(0);
	while(n--){
		d = getchar();
		cur = h;
		i = 0;
		flag = 1;
		num = 0;
		while(d != '\n' && flag != 0){			
				if(d == '0'){
				data[i++] = d - '0';
				if(cur->left == NULL){
					t = (node *)malloc(sizeof(node));
					cur->left = t;
					cur = t;
					num++;
				}else{
					cur = cur->left;
					if(cur->z == 1) {flag *= 0; break;}
				}
			}else{
				data[i++] = d - '0';
				if(cur->right == NULL){
					t = (node *)malloc(sizeof(node));
					cur->right = t;
					cur = t;
					num++;
				}else{
					cur = cur->right;
					if(cur->z == 1) {flag *= 0; break;}
				}
			}
			d = getchar();
		}// end line
		if(flag == 0 || num == 0){
			for(long j = 0; j < i; j++){
				printf("%d", data[j]);
			}
			if(d == '\n') printf("\n");
			while(d != '\n'){
				d = getchar();
				printf("%c", d);
			}
			break;
		}
		cur->z = 1;
	}
	if(!(flag == 0 || num == 0)) printf("YES\n");
	return 0;
}