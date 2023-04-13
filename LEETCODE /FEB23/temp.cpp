#include<bits/stdc++.h>
using namespace std;

#define ll long long int




bool canPlaceFlowers(vector<int>& f, int n)
{

	int s = f.size();
	if (s == 1)
	{
		if (f[0] == 1)
			if (n > 0)
				return false;
			else
				return true;
		else if (f[0] == 0)
			if (n <= 1)
				return true;
			else
				return false;
	}
	for (int i = 0; i < f.size(); ++i)
	{
		if (n == 0)
			return true;
		if (f[i] == 1)
			continue;
		if (i == 0 && f[i] == 0 && i + 1 < s && f[i + 1] == 0)
		{
			f[i] = 1;
			n--;
		}
		else if (i == s - 1 && f[i] == 0 && f[i - 1] == 0)
		{
			f[i] = 1;
			n--;
		}
		else if (f[i - 1] == 0 && f[i + 1] == 0)
		{
			f[i] = 1;
			n--;
		}

	}
	if (n == 0)
		return true;
	return false;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int tw = 5;
	// while (tw --)
	// {

	// 	string s, t;
	// 	cin >> s >> t;
	// 	if (s == t)
	// 		cout << " yes\n";
	// 	else
	// 		cout << "no\n";
	// }
	vector<int>v;
	while (1)
	{
		int k;
		cin >> k;
		if (k == -1)
			break;
		v.push_back(k);
	}
	int n;
	cin >> n;
	cout << canPlaceFlowers(v, n) << endl;

	return 0;
}

// {
// 	int bit = 0;
// // // 0:l->r
// // // 1:r->l

// vector<vector<int>>ans;
// void helper(TreeNode* root )
// {
// 	if (!root)
// 		return;

// 	queue<pair<int, TreeNode*>>q;

// 	q.push({root->val, root});
// 	q.push({ -999, NULL});

// 	while (q.size())
// 	{
// 		vector<int>v;
// 		while ( q.front().first != -999)
// 		{
// 			v.push_back(q.front().first);
// 			root = q.front().second;
// 			q.pop();
// 			if (root->left)
// 				q.push({root->left->val, root->left});
// 			if (root->right)
// 				q.push({root->right->val, root->right});
// 		}
// 		if (q.front.first  == -999)
// 		{
// 			if (bit == 0)
// 				ans.push_back(v);
// 			else if (bit)
// 			{
// 				reverse(v.begin(), v.end());
// 				ans.push_back(v);
// 			}
// 			bit ^= 1;
// 			q.pop();
// 			if (q.size() > 0)
// 				q.push({ -999, NULL});
// 		}

// 	}
// }
// vector<vector<int>> zigzagLevelOrder(TreeNode* root)
// {
// 	vector<int>v;
// 	helper(root );
// 	return ans;
// }}

class Solution {
public:
	void helper(int **a, int i, int j, int& n, vector<int>v)
	{
		if (i < 0 || j < 0 || i >= n || j >= n || v[a[i][j]] == 1 || a[i][j] == -1)
			return false;
		v[a[i][j]] = 1;
		return true;
		a[i][j] = -1;
		int c = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i][j] == 0)
				break;
			return true;
		}

		helper(a, i - 2, j - 1, n, v);
		helper(a, i - 2, j + 1, n, v);
		helper(a, i + 2, j - 1, n, v);
		helper(a, i + 2, j + 1, n, v);
		helper(a, i - 1, j - 2, n, v);
		helper(a, i + 1, j - 2, n, v);
		helper(a, i - 1, j + 2, n, v);
		helper(a, i + 1, j + 2, n, v);

	}
	bool checkValidGrid(vector<vector<int>>& grid)
	{
		int n = grid.size();
		vector<int>v(n * n - 1, 0);

		int **a = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			a[i] =  new int[n];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = grid[i][j];
			}
		}

		bool ans  = helper(a, 0, 0, n, v);
		for (int i = 0; i < n * n; ++i)
		{
			if (v[i] == 0)
				return false;
		}
		return true;
	}
};