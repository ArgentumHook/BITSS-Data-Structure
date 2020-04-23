#include<stdio.h>
#include<string.h>
struct node
{
	int x,y;
};
int m,n,map[105][105],vis[105][105],dir[4][2]={-1,0,1,0,0,-1,0,1},min=1000000;
node a[10005],temp[10005];
void dfs(int t,int x,int y)
{
	if(x==m-1 && y==n-1)
	{
		if(t<min)
		{
			min=t;
			for(int i=0;i<t;i++)
				temp[i]=a[i];
		}
		return ;
	}
	for(int k=0;k<4;k++)
	{
		int px=x+dir[k][0];
		int py=y+dir[k][1];
		if(px>=0 && px<m && py>=0 && py<n && vis[px][py]==0 && map[px][py]==0)
		{
			vis[px][py]=1;
			a[t].x=px;
			a[t].y=py;
			dfs(t+1,px,py);
			vis[px][py]=0;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	memset(vis,0,sizeof(vis));
	vis[0][0]=1;
	dfs(0,0,0);
	if(min==1000000)
	{
		printf("There is no solution!\n");
		return 0;
	}
	printf("<1,1> ");
	for(i=0;i<min;i++)
		printf("<%d,%d> ",temp[i].x+1,temp[i].y+1);
	printf("\n");
	return 0;
}
