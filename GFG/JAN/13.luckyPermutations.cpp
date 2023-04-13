#include<bits/stdc++.h>
using namespace std;

#define ll long long int
long long int sum = 0;
void dfs(vector<vector<int>> edges, int n, int node, int parent,
         unordered_map<int, int>&mp, unordered_map<int, int>&mp_arr)
{
	// cout << node << " ";
	if (mp_arr.find(node) == mp_arr.end())
		return;
	if (mp.size() == n)
	{
		sum++;
		return;
	}
	// if(adj[node])

	for (auto child : edges[node])
	{
		if (child == parent)
			continue;
		if (mp.find(child) == mp.end())
			mp[child]++;
		dfs(edges, n, child, node, mp, mp_arr);
		mp.erase(child);
	}
}
long long int luckyPermutations(int n, int e, vector<int> arr,
                                vector<vector<int>> edges)
{
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < edges.size(); ++i)
	{
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	// for (int i = 1; i < adj.size() ; ++i)
	// {
	// 	cout << i << ": ";
	// 	for (auto val : adj[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }
	unordered_map<int, int>mp_arr;
	for (int i = 0; i < n; ++i)
		mp_arr[arr[i]]++;

	for (int i = 1; i < adj.size(); ++i)
	{
		unordered_map<int, int>mp;
		mp[i]++;
		dfs(adj, n, i, -1, mp, mp_arr);
		// for (auto val : mp)
		// 	cout << val.first << " " << val.second << endl;
		// cout << endl;
	}

	return sum;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, e;
	cin >> n >> e;
	vector<int> arr;
	vector<vector<int>> graph;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}

	for (int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;
		vector<int>m;
		m.push_back(u);
		m.push_back(v);
		graph.push_back(m);
	}

	// for (int i = 0; i < graph.size() ; ++i)
	// {
	// 	cout << i << ": ";
	// 	for (auto val : graph[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }


	cout << luckyPermutations(n, e, arr, graph) << endl;




	return 0;
}