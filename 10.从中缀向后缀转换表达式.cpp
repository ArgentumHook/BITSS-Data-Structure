#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<cstring>
using namespace std;
stack<char>OP;
stack<int>Number;
queue<char>q;
int T;
char s[1005];
int t[1005];
int isp(char ch)
{
	switch(ch)
	{
		case('+'):
			return 3;
		case('-'):
			return 3;
		case('*'):
			return 5;
		case('/'):
			return 5;
		case('%'):
			return 5;
		case('('):
			return 10;
		case('^'):
			return 8;
	}
}

int icp(char ch)
{
	switch(ch)
	{
		case('+'):
			return 4;
		case('-'):
			return 4;
		case('*'):
			return 6;
		case('/'):
			return 6;
		case('%'):
			return 6;
		case('('):
			return 1;
		case('^'):
			return 7;
	}
}

void trans(char *s)
{
	memset(t,0,sizeof(t));
	for(int i=0;s[i]!='#';i++)
	{
		if((isalpha(s[i])||isdigit(s[i]))&&!t[i])
		{
			cout<<s[i];
			continue;
		}
		else if(i==0&&s[i]=='-'&&(isdigit(s[i+1])||isalpha(s[i+1])))
		{
			cout<<s[i]<<s[i+1];
			t[i+1]=1;
			continue;
		}
		else if(i>0&&s[i]=='-'&&(isdigit(s[i+1])||isalpha(s[i+1]))&&s[i-1]=='(')
		{
			cout<<s[i]<<s[i+1];
			t[i+1]=1;
			continue;
		}
		else if(!(isalpha(s[i])||isdigit(s[i])))
		{
			if(OP.empty()||s[i]=='(')
			{
				OP.push(s[i]);
				continue;
			}
			else if(s[i]==')')
			{
				while(!OP.empty()&&OP.top()!='(')
				{
					cout<<OP.top();
					OP.pop();
				}
				OP.pop();
			}
			else
			{
				while(!OP.empty()&&isp(s[i])<icp(OP.top()))
				{
					cout<<OP.top();
					OP.pop();
				}
				OP.push(s[i]);
			}
		}
	}
	while(!OP.empty())
	{
		cout<<OP.top();
		OP.pop();
	}
	cout<<endl;
}

int main()
{
	cin>>T;
	while(T--)
	{
		int flag=0,j,tag;
		while(!OP.empty())
			OP.pop();
		while(!Number.empty())
			Number.pop();
		cin>>s;
		trans(s);
	}
	return 0;
}
