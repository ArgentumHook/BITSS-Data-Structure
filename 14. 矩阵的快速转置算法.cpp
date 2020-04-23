#include<stdio.h>
#include<string.h>
typedef struct
{
	int i, j;
	int e;
}triple;
typedef struct
{
	triple data[1000];
	int mu,nu,tu;
}Matrix;
int num[1000],cpot[1000];
int main()
{
	int col,t,p,q;
	Matrix M,T;
	scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
	for(int i=1;i<= M.tu;i++)
		scanf("%d%d%d",&M.data[i].i,&M.data[i].j,&M.data[i].e);
	T.mu=M.mu;
	T.nu=M.nu;
	T.tu=M.tu;
	if(T.tu)
	{
		for(col=1;col<=M.nu;col++)
			num[col] = 0;
		for(t=1;t<= M.tu;t++)
			num[M.data[t].j]++;
		cpot[0]=1;
		cpot[1]=1;
		for(col=2;col<=M.nu;col++)
			cpot[col]=cpot[col-1]+num[col-1];
		for(p=1;p<=M.tu;p++)
		{
			col=M.data[p].j;
			q=cpot[col];
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;
			cpot[col]++;
		}
	}
	printf("num:");
	for(int i=1;i<=M.nu;i++)
		printf("%d,",num[i]);
	printf("\n");
	printf("cpot:");
	for(int i=0;i<M.nu;i++)
		printf("%d,",cpot[i]);
	printf("\n");
	for(int i=1;i<=M.tu;i++)
		printf("%d,%d,%d\n",T.data[i].i,T.data[i].j,T.data[i].e);
	return 0;
}
