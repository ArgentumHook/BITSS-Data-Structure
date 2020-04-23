#include<iostream>
using namespace std;
const int maxn = 1005;
typedef struct node 
{
	int data, left, right;
}BT;
BT Bitree[maxn], temp[maxn];
int n, a[maxn], dp[maxn][maxn], point1, point2;

int main()
{
	int i, j, k;
	cin >> n;
	a[0] = 0;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	cin >> point1 >> point2;
	if (!a[point1])
	{
		printf("ERROR: T[%d] is NULL\n", point1);
		return 0;
	}
	else if (!a[point2])
	{
		printf("ERROR: T[%d] is NULL\n", point2);
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		Bitree[i].data = a[i];
		Bitree[i].left = (2 * i > n ? -1 : 2 * i);
		Bitree[i].right = (2 * i + 1 > n ? -1 : 2 * i + 1);
	}
	i = point1, j = point2;
	while (i >= 1 && j >= 1)
	{
		if (i == j)
		{
			k = i;
			break;
		}
		else if (i < j)
			j /= 2;
		else
			i /= 2;
	}
	cout << k << " " << Bitree[k].data << endl;
}
