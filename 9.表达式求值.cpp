#include<cstdio>
#include<cstring>
#include<stack>
#include<iostream>
using namespace std;
stack<char> OP;
stack<int>  Number;
char str[100005];
int errorType;
int fpow(int a, int b)
{
	int ans = 1;
	while (b>0)
	{
		if (b % 2 == 1)
			ans *= a;
		b /= 2;
		a *= a;
	}
	return ans;
}

int isp(char ch)
{
	switch (ch)
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
	switch (ch)
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

int calculate(char op, int a, int b)
{
	switch (op)
	{
		case('+'):
			return a + b;
		case('-'):
			return a - b;
		case('*'):
			return a * b;
		case('/'):
			return a / b;
		case('%'):
			return a % b;
		case('^'):
			return fpow(a, b);
	}
}

int solve(char *s)
{
	int num = 0;
	errorType = 0;
	int numleft = 0;
	int numright = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			if (i>0 && s[i - 1] == ')')
			{
				errorType = 1;
				return -1;
			}
			num = num * 10 + s[i] - '0';
		}

		else if (!(s[i] >= '0'&&s[i] <= '9'))
		{
			if (i > 0 && s[i - 1] == '(' && (s[i] == '%' || s[i] == '*' || s[i] == '/' || s[i] == '^'))
			{
				errorType = 1;
				return -1;
			}
			if (i>0 && (s[i - 1] >= '0'&&s[i - 1] <= '9'))
			{
				Number.push(num);
				num = 0;
			}
			else if (i == 0 && (s[i] == '+' || s[i] == '-') && (s[i + 1] >= '0'&&s[i + 1] <= '9'))
			{
				i++;
				int k = i;
				while (s[k] && (s[k] >= '0'&&s[k] <= '9'))
				{
					num = num * 10 + s[k] - '0';
					k++;
				}
				if (s[i - 1] == '-') num *= -1;
				i = k - 1;
				continue;
			}
			else if (i == 0 && (s[i] == '%' || s[i] == '*' || s[i] == '/' || s[i] == '^'))
			{
				errorType = 1;
				return -1;
			}
			else if (i>0 && !(s[i - 1] >= '0'&&s[i - 1] <= '9') && (s[i] == '+' || s[i] == '-') && (s[i + 1] >= '0'&&s[i + 1] <= '9'))
			{
				i++;
				int k = i;
				while (s[k] && (s[k] >= '0'&&s[k] <= '9'))
				{
					num = num * 10 + s[k] - '0';
					k++;
				}
				if (s[i - 1] == '-') num *= -1;
				i = k - 1;
				continue;
			}
			if (OP.empty() || s[i] == '(')
			{
				if (s[i] == '(')
				{
					if (i > 0 && (s[i - 1] >= '0'&&s[i - 1] <= '9' || s[i - 1] == ')'))
					{
						errorType = 1;
						return -1;
					}
				}
				OP.push(s[i]);
				if (s[i] == '(')
					numleft++;
				continue;
			}
			else if (s[i] == ')')
			{
				numright++;
				if (numright > numleft)
				{
					errorType = 1;
					return -1;
				}
				char op;
				while (!OP.empty() && (op = OP.top()) != '(')
				{
					int b = Number.top();
					Number.pop();
					int a = Number.top();
					Number.pop();
					if (b == 0 && op == '/')
					{
						errorType = 2;
						return -1;
					}
					else if (b < 0 && op == '^')
					{
						errorType = 1;
						return -1;
					}
					else
						Number.push(calculate(op, a, b));
					OP.pop();
				}
				OP.pop();
			}
			else
			{
				char op;
				while (!OP.empty() && icp(OP.top()) > isp(s[i]))
				{
					op = OP.top();
					int b = Number.top();
					Number.pop();
					int a = Number.top();
					Number.pop();
					if (b == 0 && op == '/')
					{
						errorType = 2;
						return -1;
					}
					else if (b < 0 && op == '^')
					{
						errorType = 1;
						return -1;
					}
					else
						Number.push(calculate(op, a, b));
					OP.pop();
				}
				OP.push(s[i]);
			}
		}
	}
	if (s[strlen(s) - 1] >= '0'&&s[strlen(s) - 1] <= '9')
		Number.push(num);
	if (!OP.empty() || !Number.empty())
	{

		while (!OP.empty())
		{
			char op = OP.top();
			if (op == '(')
			{
				errorType = 1;
				return -1;
			}
			int b = Number.top();
			Number.pop();
			int a = Number.top();
			Number.pop();
			if (b == 0 && op == '/')
			{
				errorType = 2;
				return -1;
			}
			else if (b < 0 && op == '^')
			{
				errorType = 1;
				return -1;
			}
			else
				Number.push(calculate(op, a, b));
			OP.pop();
		}
		return Number.top();
	}
	else return num;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		while (!OP.empty())
			OP.pop();
		while (!Number.empty())
			Number.pop();
		cin >> str;
		int ans = solve(str);
		if (errorType == 1)
			cout << "error." << endl;
		else if (errorType == 2)
			cout << "Divide 0." << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
