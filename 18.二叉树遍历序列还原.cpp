//#include"pch.h"
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100005;
typedef struct Node 
{
	char data;
	struct Node *left;
	struct Node *right;
}Binode, *BiTree;
char inOrder[maxn], postOrder[maxn];

BiTree Reduction(char *In, char *Post, int P_beg, int P_end, int I_beg, int I_end);
int Judge(BiTree T, int depth);

int main()
{
	ios::sync_with_stdio(false);
	cin >> inOrder;
	cin >> postOrder;
	int len = strlen(inOrder) - 1;
	BiTree T = Reduction(inOrder, postOrder, 0, len, 0, len);
	int dep = 0;
	while (1)
	{
		if (!Judge(T, dep))
			break;
		dep++;
	}
	cout << endl;
	return 0;
}

BiTree Reduction(char *In, char *Post, int P_beg, int P_end, int I_beg, int I_end)
{
	BiTree T = (BiTree)malloc(sizeof(Binode));
	T->data = Post[P_end];
	int i = I_beg;
	while (In[i] != Post[P_end])
		i++;
	if (In[I_beg] == Post[P_end])
		T->left = NULL;
	else
		T->left = Reduction(In, Post, P_beg, P_beg + i - I_beg - 1, I_beg, i-1);
	if (In[I_end] == Post[P_end])
		T->right = NULL;
	else
		T->right = Reduction(In, Post, P_beg + i - I_beg, P_end - 1, i + 1, I_end);
	return T;
}

int Judge(BiTree T, int depth)
{
	if (T == NULL || depth < 0)
		return 0;
	if (!depth)
	{
		cout << T->data;
		return 1;
	}
	depth--;
	return Judge(T->left, depth) + Judge(T->right, depth);
}
