#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int snakesAndLadders(vector<vector<int>>& board)
{
	int n = board.size();
	unordered_map<int, pair<int, int>>mp;
	int flag = 1;
	int step = 1;
	pair<int, int>p;
	for (int i = board.size() - 1; i >= 0; --i)
	{
		if (flag == 1)
		{
			for (int j = 0; j < board.size(); j++)
			{
				p = make_pair(i, j);
				mp[step] = p;
				step++;
			}
		}
		else if (flag == 0)
		{
			for (int j = board.size() - 1; j >= 0; j--)
			{
				p = make_pair(i, j);
				mp[step] = p;
				step++;
			}
		}
		flag = flag ^ 1;
	}

	// for (auto val : mp)
	// 	cout << val.first << " " << val.second.first
	// 	     << " " << val.second.second << " " << endl;


	queue<int>q;
	bool visited[n] = {false};
	q.push(1);
	visited[1] = true;

	step = 0;
	while (!q.empty())
	{
		int N = q.size();
		while (N--)
		{

			int x = q.front();
			q.pop();
			// cout << x << endl;
			if (x == n * n)
				return step;//dfs ki tarah sab explore karne ki zaroorat nahi

			for (int i = x + 1; i <= x + 6; i++)
			{
				if (i > n * n)
					break;
				pair<int, int> coordinate = mp[i];
				int r = coordinate.first;
				int c = coordinate.second;
				if (visited[i])
					continue;
				visited[i] = true;
				if (board[r][c] == -1)
				{
					// cout << i << " " << r << " " << c << " " << board[r][c] << endl;
					q.push(i);
				}
				else
				{
					q.push(board[r][c]);
				}
			}
		}
		step++;
	}
	return -1;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>board;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		vector<int>v;
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		board.push_back(v);
	}

	cout <<  snakesAndLadders(board) << endl;

	return 0;
}