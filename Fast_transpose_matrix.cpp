#include <stdio.h>
#include <cstdlib>
# define MAXSIZE 20000
typedef struct{
	int i, j, e;
}Triple;
typedef struct{
	Triple data[MAXSIZE];
	int mu, nu, tu;
}Matrix;

int main(){
	Matrix D, N;
	int num[MAXSIZE], cpot[MAXSIZE];
	int i, t;
	if(scanf("%d %d %d", &D.mu, &D.nu, &D.tu)!=3) exit(0);
	for(int i = 0; i < D.tu; i++){
		if(scanf("%d %d %d", &D.data[i].i, &D.data[i].j, &D.data[i].e)!=3)exit(0); 
	}
	N.mu = D.nu; N.nu = D.mu; N.tu = D.tu;
	for (i = 1; i <= D.nu; i++) num[i] = 0;
	for (i = 0; i < D.tu; i++) num[D.data[i].j]++;
	cpot[1] = 1;
	for (i = 2; i <= D.nu; i++) cpot[i] = cpot[i-1] + num[i-1];
	printf("num:");
	for(i = 1; i <= D.nu; i++) printf("%d,", num[i]);
	printf("\ncpot:");
	for(i = 1; i <= D.nu; i++) printf("%d,", cpot[i]);
	printf("\n");
	for (i = 0; i < D.tu; i++){
		t = cpot[D.data[i].j] - 1;
		N.data[t].i = D.data[i].j;
		N.data[t].j = D.data[i].i;
		N.data[t].e = D.data[i].e;
		cpot[D.data[i].j]++;
	}
	for(i = 0; i < N.tu; i++) printf("%d,%d,%d\n", N.data[i].i, N.data[i].j, N.data[i].e);
}
