#include<stdio.h>
#include<malloc.h>
typedef struct node1
{
	int x,y,z;
}Triple;
typedef struct node2
{
	int mu,nu,tu;
	Triple s[105];
}Matrix;
Matrix *multiply(Matrix *A,Matrix *B)
{
	Matrix *C;
	int tmp[B->nu+1],num[B->nu+1],rpot[B->nu+1];
	C=(Matrix*)malloc(sizeof(Matrix));
	if(A->nu!=B->mu)
		return NULL;
	C->mu=A->mu;
	C->nu=B->nu;
	if(A->tu*B->tu==0)
	{
		C->tu=0;
		return C;
	}
	for(int i=1;i<=B->mu;i++)
		num[i]=0;
	for(int i=0;i<B->tu;i++)
		num[B->s[i].x]++;
	rpot[1]=0;
	for(int i=2;i<=B->mu;i++)
		rpot[i]=rpot[i-1]+num[i-1];
	int r=0,p=0,k,t,q,j;
	for(int i=1;i<=A->mu;i++)
	{
		for(j=1;j<=B->nu;j++)
			tmp[j]=0;
		while(i==A->s[p].x)
		{
			k=A->s[p].y;
			if(k<B->mu)
				t=rpot[k+1];
			else
				t=B->tu;
			for(q=rpot[k];q<t;q++)
			{
            	j=B->s[q].y;
            	tmp[j]+=A->s[p].z*B->s[q].z;
			}
			p++;
		}
		for(j=1;j<=B->nu;j++)
		{
        	if(tmp[j]!=0)
			{
            	C->s[r]={i,j,tmp[j]};
            	r++;
			}
        }
	}
	C->tu=r;
	return C;
}
int main()
{
	Matrix *A,*B,*C;
	A=(Matrix*)malloc(sizeof(Matrix));
    B=(Matrix*)malloc(sizeof(Matrix));
    scanf("%d %d %d",&A->mu,&A->nu,&A->tu);
    for(int i=0;i<A->tu;i++)
        scanf("%d %d %d",&A->s[i].x,&A->s[i].y,&A->s[i].z);
	scanf("%d %d %d",&B->mu,&B->nu,&B->tu);
	for(int i=0;i<B->tu;i++)
        scanf("%d %d %d",&B->s[i].x,&B->s[i].y,&B->s[i].z);
    C=multiply(A,B);
    printf("%d\n%d\n%d\n",C->mu,C->nu,C->tu);
    for(int i=0;i<C->tu;i++)
        printf("%d,%d,%d\n",C->s[i].x,C->s[i].y,C->s[i].z);
}
