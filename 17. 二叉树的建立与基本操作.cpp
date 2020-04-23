//#include"pch.h"
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int num = 0;
typedef struct Node 
{
	char data;
	struct Node *left;
	struct Node *right;
}Binode, *BiTree;
queue <BiTree> q;

void BuildTree();
void DisplayTree(BiTree T, int depth);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void SwapTree(BiTree T);
int CountLeaf(BiTree T);

int main()
{
	BiTree T = (BiTree)malloc(sizeof(Binode));
	q.push(T);
	BuildTree();
	cout << "BiTree" << endl;
	DisplayTree(T, 0);
	cout << "pre_sequence  : ";
	PreOrder(T);
	cout << endl;
	cout << "in_sequence   : ";
	InOrder(T);
	cout << endl;
	cout << "post_sequence : ";
	PostOrder(T);
	cout << endl;
	cout << "Number of leaf: " << CountLeaf(T) << endl;
	SwapTree(T);
	cout << "BiTree swapped" << endl;
	DisplayTree(T, 0);
	cout << "pre_sequence  : ";
	PreOrder(T);
	cout << endl;
	cout << "in_sequence   : ";
	InOrder(T);
	cout << endl;
	cout << "post_sequence : ";
	PostOrder(T);
	cout << endl;
}

void BuildTree()
{
	char ch;
	BiTree T, S;
	while (!q.empty())
	{
		ch = getchar();
		T = q.front();
		q.pop();
		if (ch == '\n')
			break;
		T->data = ch;
		S = (BiTree)malloc(sizeof(Binode));
		S->data = '\0';
		T->left = S;
		q.push(S);
		S = (BiTree)malloc(sizeof(Binode));
		S->data = '\0';
		T->right = S;
		q.push(S);
	}
}

void DisplayTree(BiTree T, int depth)
{
	if (T->data != '#' &&T->data != '\0') 
	{
		for (int i = 1; i <= depth; i++)
			cout << "    ";
		cout << T->data << endl;
		depth++;
		DisplayTree(T->left, depth);
		DisplayTree(T->right, depth);
	}
}

void PreOrder(BiTree T)
{
	if (T->data != '#'&&T->data != '\0') 
	{
		cout << T->data;
		PreOrder(T->left);
		PreOrder(T->right);
	}
}

void InOrder(BiTree T)
{
	if (T->data != '#'&&T->data != '\0')
	{
		InOrder(T->left);
		cout << T->data;
		InOrder(T->right);
	}
	return;
}

void PostOrder(BiTree T)
{
	if (T->data != '#'&&T->data != '\0')
	{
		PostOrder(T->left);
		PostOrder(T->right);
		cout << T->data;
	}
	return;
}

void SwapTree(BiTree T)
{
	if (T->data != '#'&&T->data != '\0')
	{
		swap(T->left, T->right);
		SwapTree(T->left);
		SwapTree(T->right);
	}
	return;
}

int CountLeaf(BiTree T)
{
	if (T->data != '#'&&T->data != '\0') 
	{
		CountLeaf(T->left);
		if ((T->left->data == '#' || T->left->data == '\0') && (T->right->data == '#' || T->right->data == '\0'))
			num++;
		CountLeaf(T->right);
	}
	return num;
}
