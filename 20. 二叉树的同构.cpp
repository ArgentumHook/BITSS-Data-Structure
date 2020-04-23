#include<iostream>
#include<cstring>
#define Null -2
using namespace std;
const int maxn = 100005;
typedef struct node
{
	char data;
	int left;
	int right;
}BT;
BT t1[maxn], t2[maxn];
bool visit[maxn];
int n;
char l, r;

int build(BT *tree);
bool Judge(int a, int b);

int main()
{
	int Root1 = build(t1);
	int Root2 = build(t2);
	if (Judge(Root1, Root2))
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	return 0;
}

int build(BT *tree)
{
	int i;
	memset(visit, false, sizeof(visit));
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> tree[i].data >> l >> r;
		if (l != '-')
		{
			tree[i].left = l - '0';
			visit[tree[i].left] = true;
		}
		else
			tree[i].left = Null;
		if (r != '-')
		{
			tree[i].right = r - '0';
			visit[tree[i].right] = true;
		}
		else
			tree[i].right = Null;
	}
	for (i = 0; i < n; i++)
		if (!visit[i])
			break;
	return i;
}

bool Judge(int root1, int root2)
{
	if ((root1 == Null && root2 != Null) && (root1 != Null && root2 == Null))
		return false;
	if (t1[root1].data != t2[root2].data)
		return false;
	if (root1 == Null && root2 == Null)
		return true;
	if (t1[root1].left == Null && t2[root2].left == Null)
		return Judge(t1[root1].right, t2[root2].right);
	if ((t1[root1].left != Null && t2[root2].left != Null) && (t1[t1[root1].left].data == t2[t2[root2].left].data))
		return (Judge(t1[root1].left, t2[root2].left) && Judge(t1[root1].right, t2[root2].right));
	else
		return (Judge(t1[root1].left, t2[root2].right) && Judge(t1[root1].right, t2[root2].left));
}
