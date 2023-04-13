#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void print(int **dp, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}
int paths = 0;
int n_zeroes = 0;
void helper(int **dp, int r, int c , int max_row, int  max_col, int cnt_zeroes)
{
	if (r < 0 || r >= max_row || c < 0 || c >= max_col || dp[r][c] == -1)
		return;
	// cout << cnt_zeroes << endl;
	// if (cnt_zeroes == 8)
	// 	cout << r << " " << c << endl;

	if (dp[r][c] == 2)
	{
		// cout << cnt_zeroes << endl;
		if (cnt_zeroes == n_zeroes)
			paths++;
		return;
	}
	int k = dp[r][c] ;
	if (dp[r][c] == 0)
		cnt_zeroes++;
	dp[r][c] =  -1;

	helper(dp , r + 1, c, max_row, max_col, cnt_zeroes );
	helper(dp , r - 1, c, max_row, max_col, cnt_zeroes );
	helper(dp , r, c + 1, max_row, max_col, cnt_zeroes );
	helper(dp , r, c - 1, max_row, max_col, cnt_zeroes );
	cnt_zeroes--;
	dp[r][c] = k;
}
int uniquePathsIII(vector<vector<int>>& grid)
{
	int r = grid.size();
	int c = grid[0].size();
	int intital_row , initail_col;
	int **dp = new int*[grid.size()];
	for (int i = 0; i < grid.size(); i++)
	{
		dp[i] = new int[grid[i].size()];
		for (int j = 0; j < grid[i].size(); j++)
		{
			dp[i][j] = grid[i][j];
			if (grid[i][j] == 0) n_zeroes++;
			if (grid[i][j] == 1)
				intital_row = i , initail_col = j;
		}
	}

	// print(dp, r, c);
	// cout << n_zeroes << endl;
	int cnt = 0;
	helper(dp, intital_row , initail_col, r, c, cnt);
	for (int i = 0; i < grid.size(); i++)
		delete [] dp[i];
	delete[] dp;
	return paths;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	vector<vector<int>>grid;
	for (int i = 0; i < n; ++i)
	{
		int e;
		cin >> e;
		vector<int>v;
		while (e--)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}

		grid.push_back(v);

	}
	cout << uniquePathsIII(grid) << endl;

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (auto val : grid[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }

	return 0;
}