#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<int> dfs( vector<vector<int>>& edges, string &labels, vector<int>&v, int cur_ind, int parentIndex )
{
	vector<int> alphabet_arr(26, 0);
	for (auto child : edges[cur_ind])
	{
		if (child == parentIndex) //beta baap to skip this case
			continue;
		vector<int>child_arr = dfs( edges, labels, v, child, cur_ind);
		// cout << child << endl;
		for (int i = 0; i < 26; ++i)
			alphabet_arr[i] += child_arr[i];
	}
	v[cur_ind] = ++alphabet_arr[labels[cur_ind] - 'a'];;
	return alphabet_arr;

}
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
{
	vector<vector<int>>adj(n);
	for (int i = 0; i < edges.size(); ++i)
	{
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	vector<int>v(n, 0);
	vector<int> alphabet_arr(26, 0);
	alphabet_arr = dfs( adj, labels, v, 0, -1);
	return v;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

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


	// for (int i = 0; i < e; ++i)
	// {
	// 	for (auto val : edges[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }
	cin.get();
	string labels ;
	cin >> labels;
	vector<int>v = countSubTrees(n, edges, labels);
	for (auto val : v)
		cout << val << " ";
	return 0;
}