#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int temp = 20;
void print(vector<int>p)
{
	for (auto val : p)
		cout << val << " ";
	cout << std::endl;
}
vector<vector<int>>paths;
void dfs(vector<vector<int>>& graph, int src, int des, vector<int>v)
{
	// if (--temp < 0)
	// 	exit(0);
	// cout << "\nsrc2::" << src << " \n";
	if (src == des)
	{
		paths.push_back(v);
		// cout << "\n ans::--------------\n";
		// print(v);
		// cout << endl;
		v.pop_back();
		return;
	}
	if (graph[src].size() > 0)
		for (auto val : graph[src])
		{
			// explore
			v.push_back(val);
			// cout << "src:" << src << ": pushing val " << val << "   ";
			// print(v);
			dfs(graph, val, des, v);
			// cout << "\npoping:" << v[v.size() - 1] << endl << endl;
			v.pop_back();
		}
	v.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{


	int n = graph.size();
	int des = n - 1;
	vector<int>v;
	v.push_back(0);
	dfs(graph, 0, des, v);
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
	vector<vector<int>>graph;
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

		graph.push_back(v);

	}
	vector<vector<int>>paths = allPathsSourceTarget(graph);
	for (int i = 0; i < n; ++i)
	{
		for (auto val : paths[i])
			cout << val << " ";
		cout << endl;
	}


	return 0;
}