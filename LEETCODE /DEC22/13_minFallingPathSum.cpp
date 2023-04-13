#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int minFallingPathSum(vector<vector<int>>& matrix)
{
	int minsum = INT_MAX;
	int col_end = matrix[0].size() - 1;
	int row_end = matrix.size() - 1;
	int cur_sum = 0;
	for (int row = row_end - 1 ; row >= 0; row--)
	{
		for (int col = 0; col <= col_end; col++)
		{
			//neither at first nor at last col
			if (col != 0 && col != col_end   )
			{
				matrix[row][col] += min(matrix[row + 1][col - 1], min(matrix[row + 1][col], matrix[row + 1][col + 1]));
			}
			else if (col == 0 )
			{
				matrix[row][col] +=  min(matrix[row + 1][col], matrix[row + 1][col + 1]);
			}
			else if (col == col_end)
			{
				matrix[row][col] +=  min(matrix[row + 1][col], matrix[row + 1][col - 1]);
			}
			// cout << ", cur_sum " << cur_sum << endl;
		}
	}
	for (int i = 0; i < matrix[0].size(); ++i)
	{
		minsum = min(minsum , matrix[0][i]);
	}
	return minsum;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>>v;
	for (int i = 0; i < n; ++i)
	{
		vector<int>m;
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			m.push_back(k);
		}
		v.push_back(m);
	}
	cout << minFallingPathSum(v) << endl;
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	for (int j = 0; j < v[i].size(); j++)
	// 	{

	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	return 0;
}