#include<iostream>
#include<stack>
using namespace std;
int n,m,a[10005];
stack<int>s;
int main()
{
	int cnt=0,j;
	bool flag;
	while(cin>>n>>m)
	{
		if(!n&&!m)
			break;
		cnt++;
		if(cnt>1)
			cout<<endl;
		while(m--)
		{
			flag=true,j=1;
			for(int i=0;i<n;i++)
				cin>>a[i];
			for(int i=0;i<n;i++)
			{
				if(!flag)
					continue;
				for(;j<=a[i];j++)
					s.push(j);
				if(s.top()!=a[i])
				{
					flag=false;
					continue;
				}
				s.pop();
			}
			if(flag)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}
