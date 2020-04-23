 #include<iostream>
#include<vector>
using namespace std;
int n,k,m,b[100000];
vector<int>a;
void print()
{
	int i;
	if(n<=10)
	{
		cout<<b[1];
		for(i=2;i<=n;i++)
			cout<<" "<<b[i];
		cout<<endl;
		a.clear();
		return ;
	}
	else
	{
		for(i=1;i<=n-1;i++)
		{
			if(i%10==0)
				cout<<b[i]<<endl;
			else
				cout<<b[i]<<" ";
		}
		cout<<b[n]<<endl;
		a.clear();
		return ;
	}
}
int main()
{
	scanf("%d,%d,%d",&n,&k,&m);
	if(n<1||k<1||m<1)
	{
		cout<<"n,m,k must bigger than 0."<<endl;
		return 0;
	}
	else if(k>n)
	{
		cout<<"k should not bigger than n."<<endl;
		return 0;
	}
	int i,j,cnt;
	for(i=1;i<=n;i++)
		a.push_back(i);
    j=k-1,cnt=1;
    while(!a.empty())
    {
    	if(j+m-1>=a.size())
			j=(j+m-1)%a.size();
		else
			j=j+m-1;
		b[cnt++]=a[j];
		a.erase(a.begin()+j);
	}
	print();
}
