#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100005;
char str[maxn];
int Beg = 0, End;
int main()
{
	int op;
	gets(str);
	cout << "generic list: " << str << endl;
	End = strlen(str) - 1;
	while (cin >> op)
	{
		if (op == 1)
		{
			cout << "destroy tail\n";
			cout << "free list node\n";
			cout << "generic list: ";
			int top = -1;
			for (int i = Beg; i < strlen(str); i++)
			{
				if (str[i] == '(')
				{
					top++;
					if (top == 0)
						Beg = i + 1;
					continue;
				}
				if (str[i] == ')')
				{
					top--;
					if (top == 0)
					{
						End = i;
						break;
					}
					continue;
				}
				if (str[i] == ','&&top == 0)
				{
					End = i - 1;
					break;
				}
			}
			for (int i = Beg; i <= End; i++)
				cout << str[i];
			cout << endl;
		}
		else
		{
			cout << "free head node\n";
			cout << "free list node\n";
			cout << "generic list: ";
			int top = -1;
			bool isEmpty = false;
			for (int i = Beg; i < strlen(str); i++)
			{
				if (i == End)
				{
					isEmpty = true;
					break;
				}
				if (str[i] == '(')
					top++;
				if (str[i] == ')')
					top--;
				if (str[i] == ','&&top == 0)
				{
					str[i] = '(';
					Beg = i;
					break;
				}
			}
			if (isEmpty)
			{
				cout << "()\n";
				continue;
			}
			for (int i = Beg; i <= End; i++)
				cout << str[i];
			cout << endl;
		}
	}
	return 0;
}
