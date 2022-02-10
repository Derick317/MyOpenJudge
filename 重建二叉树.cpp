//OpenJudge 2255:重建二叉树
//给定一棵二叉树的前序遍历和中序遍历的结果，求其后序遍历。
//每组输入包含两个字符串，分别为树的前序遍历和中序遍历。每个字符串中只包含大写字母且互不重复。

#include<iostream>
using namespace std;
struct BinaryTree
{
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree* parent;
	char info;
};

BinaryTree* Create_by_pre_in(char* ptLR, char* qLtR,int num);

int main()
{
	char tLR[1000];
	char LtR[1000];
	int num = 0;

	while (cin >> LtR >> tLR)
	{
		for (int num = 0; tLR[num + 1] != '/0'; num++);

	}
}
	

BinaryTree* Create_by_pre_in(char* ptLR, char* qLtR, int num)
{
	char* leftLtR, * rightLtR, * lefttLR, * righttLR;
	int leftnum, rightnum;
	BinaryTree* root = new BinaryTree;
	root->info = *ptLR;
	leftLtR = qLtR;
	righttLR=lefttLR = qLtR + 1;
	for (leftnum = 0; *qLtR != *ptLR; leftnum++)
	{
		qLtR++;
		righttLR++;
	}
	rightLtR = qLtR + 1;
	rightnum = num - 1 - leftnum;

	if (leftnum == 0)
		leftLtR = lefttLR = NULL;
	else
	{
		root->left = Create_by_pre_in(lefttLR, leftLtR, leftnum);
	}
	if (rightnum == 0)
		rightLtR = righttLR = NULL;
	else
	{
		root->right = Create_by_pre_in(righttLR, rightLtR, rightnum);
	}

	return root;
}
