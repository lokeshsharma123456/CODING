#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long int
void preorder(TreeNode *root, vector<int>&v)
{
	if (root == nullptr)
		return;
	v.push_back(root->val);
	preorder(root->left, v);
	preorder(root->right, v);
}
void inorder(TreeNode *root, vector<int>&v)
{
	if (root == nullptr)
		return;
	inorder(root->left, v);
	v.push_back(root->val);
	inorder(root->right, v);
}


bool isSameTree(TreeNode* p, TreeNode* q)
{
	vector<int>in_p, in_q, pre_p, pre_q;
	inorder(p, in_p);
	inorder(q, in_q);
	preorder(p, in_p);
	preorder(q, in_q);
	if (in_p == in_q && in_p == in_q)return true;
	else
		return false;

}

void preorder(TreeNode *p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	if (p != nullptr && q == nullptr || p == nullptr && q != nullptr)
		return false;
	if (p->val != q->val)
		return false;
	preorder(p->left , q->left);
	preorder(p->right , q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	return preorder(p, q);
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	return 0;
}