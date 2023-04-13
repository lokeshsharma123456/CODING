#include<bits/stdc++.h>
using namespace std;

#define ll long long int

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high)
	{

		if (!root)
			return 0;
		if (high < root->val)
			return rangeSumBST(root->left , low , high);
		if (root->val < low)
			return rangeSumBST(root->right , low , high);

		l = rangeSumBST(root->left , low , high);

		int x = (low <= root->val && root->val <= high) ? root->val : 0;

		r = rangeSumBST(root->right , low , high);

		return l + x + r;
	}
};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	return 0;
}