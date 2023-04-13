#include<bits/stdc++.h>
using namespace std;

#define ll long long int
// int path = 0;
int temp = 50;
int dfs(vector<vector<int>>& edges, vector<bool>& hasApple, int curr_index, int parent_index)
{
	int time = 0;
	for (auto &child_index : edges[curr_index])
	{
		if (child_index == parent_index)
			continue;

		int time_from_child =  dfs(edges, hasApple, child_index, curr_index);
		if (time_from_child > 0 || hasApple[child_index])
			time += time_from_child + 2;

	}
	return time;
}
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
{
	int sum = 0;
	vector < vector<int>>v(n);
	for (int i = 0; i < edges.size(); ++i)
	{
		v[edges[i][0]].push_back(edges[i][1]);
		v[edges[i][1]].push_back(edges[i][0]);
	}


	sum = dfs(v, hasApple, 0, -1);

	return sum;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		int e;
		cin >> e;
		vector<vector<int>>edges;
		vector<bool>hasApple;

		for (int i = 0; i < e; ++i)
		{
			vector<int>v;
			int a, b;
			cin >> a >> b;
			v.push_back(a);
			v.push_back(b);
			edges.push_back(v);
		}

		for (int i = 0; i < n; ++i)
		{
			bool k;
			cin >> k;

			hasApple.push_back(k);
		}
		// for (int i = 0; i < e; ++i)
		// {
		// 	for (auto val : edges[i])
		// 		cout << val << " ";
		// 	cout << endl;
		// }
		cout << minTime(n, edges, hasApple) << endl;

	}

	return 0;
}













class Solution1 {
public:
	int helper(vector<vector<int>>& edges, vector<bool>& hasApple, int index)
	{
		// if (temp-- < 0)
		// 	exit(0);

		int n = edges[index].size();
		// cout << "index "  << index << " ,hasApple: " << hasApple[index]  << endl;
		if (n == 0)
		{
			if (hasApple[index])
				return 2;
			else
				return 0;
		}
		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			s += helper(edges, hasApple, edges[index][i]);
		}

		if (hasApple[index])
			return  s + 2;

		if (s)
			return  s + 2;
		else
			return s;
		// cout << "index :" << index << " rst  " << s << endl;

		// if (hasApple[index])
		// 	return  a + b + 2;

		// if (a || b)
		// 	return  a + b + 2;
		// else
		// 	return a + b;

	}
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
	{
		int sum = 0;
		vector < vector<int>>v(n);
		for (int i = 0; i < edges.size(); ++i)
		{
			v[edges[i][0]].push_back(edges[i][1]);
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (auto val : v[i])
		// 		cout << val << " ";
		// 	cout << endl;
		// }
		sum = helper(v, hasApple, 0);
		if (sum > 0)
			return sum - 2;

		return sum;
	}
};