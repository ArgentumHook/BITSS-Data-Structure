#include<iostream>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
char s[1005];

bool check(char *s)
{
	stack<char>sta;
	map<char,char>match;
	match[')']='(';
	match[']']='[';
	match['}']='{';
	for(int i=0;s[i];i++)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
			sta.push(s[i]);
		else if(s[i]==')'||s[i]==']'||s[i]=='}')
		{
			if(sta.empty()||sta.top()!=match[s[i]])
				return false;
			else
				sta.pop();
		}
	}
	return true;
}

int main()
{
	cin>>s;
	if (check(s))
		cout<<"Match succeed!\n";
	else
		cout<<"Match false!\n";
	return 0;
}
