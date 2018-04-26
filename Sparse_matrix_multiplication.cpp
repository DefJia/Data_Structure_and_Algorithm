#include <stdio.h>
#include <cstdlib>
# define MAXSIZE 100000
typedef struct{
	int i, j, e;
}Triple;
typedef struct{
	Triple data[MAXSIZE];
	int num[MAXSIZE], cpot[MAXSIZE];
	int mu, nu, tu;
}Matrix;
void Create_matrix(Matrix &D){
	if(scanf("%d\n%d\n%d\n", &D.mu, &D.nu, &D.tu)!=3) exit(0);
	for(int i = 0; i < D.tu; i++){
		if(scanf("%d %d %d", &D.data[i].i, &D.data[i].j, &D.data[i].e)!=3)exit(0); 
	}
}
void Fast_trans(Matrix &D, Matrix &N){
	int i, t;
	N.mu = D.nu; N.nu = D.mu; N.tu = D.tu;
	for (i = 1; i <= D.nu; i++) N.num[i] = 0;
	for (i = 0; i < D.tu; i++) N.num[D.data[i].j]++;
	N.cpot[1] = 1;
	for (i = 2; i <= D.nu; i++) N.cpot[i] = N.cpot[i-1] + N.num[i-1];
	for (i = 0; i < D.tu; i++){
		t = N.cpot[D.data[i].j] - 1;
		N.data[t].i = D.data[i].j;
		N.data[t].j = D.data[i].i;
		N.data[t].e = D.data[i].e;
		N.cpot[D.data[i].j]++;
	}
}
void Index(Matrix &D){
	int i;
	for (i = 1; i <= D.mu; i++) D.num[i] = 0;
	for (i = 0; i < D.tu; i++) D.num[D.data[i].i]++;
	D.cpot[1] = 1;
	for (i = 2; i <= D.mu; i++) D.cpot[i] = D.cpot[i-1] + D.num[i-1];
}
void Multi_matrix(Matrix &M, Matrix &N, Matrix &MN){
	MN.mu = M.mu; MN.nu = N.nu; MN.tu = 0;
	Triple melem, nelem;
	int mi, ni, nj, i, sum[MAXSIZE];
	for (i = 0; i < MAXSIZE; i++) sum[i] = 0;
	if (M.tu * N.tu != 0){
		for (mi = 0; mi < M.tu; mi++){
			melem = M.data[mi];
			ni = melem.j;
			for(nj = 0; nj < N.num[ni]; nj++){
				nelem = N.data[N.cpot[ni]+nj-1];
				sum[melem.i * MN.nu + nelem.j] += melem.e * nelem.e;
				//printf("%d-%d-%d-%d-%d-%d\n", melem.i, melem.j, melem.e, nelem.i, nelem.j, nelem.e);
			}
		}
		int q = 0;
		for(mi = 1; mi <= MN.mu; mi++){
			for(ni = 1; ni <= MN.nu; ni++){
				if (sum[mi * MN.nu + ni]) {
					MN.data[q].i = mi;
					MN.data[q].j = ni;
					MN.data[q++].e = sum[mi * MN.nu + ni];
					MN.tu++;
				}
			}
		}
	}
}
void Output_matrix(Matrix &MN) {
	printf("%d\n%d\n%d\n", MN.mu, MN.nu, MN.tu);
	for(int i = 0; i < MN.tu; i++) printf("%d,%d,%d\n", MN.data[i].i, MN.data[i].j, MN.data[i].e);
}
int main(){
	Matrix M, N, MN;
	Create_matrix(M); Create_matrix(N);
	Index(N);
	Multi_matrix(M, N, MN);
	Output_matrix(MN);
}
