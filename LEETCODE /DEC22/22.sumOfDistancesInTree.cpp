#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<int>cnt, dis;
void dfs(vector<int>*adjList, int src , int parent)
{
	for (auto child : adjList[src])
	{
		if (child == parent)
			continue;
		dfs(adjList, child, src);

		cnt[src] += cnt[child];
		dis[src] += dis[child] + cnt[child];

	}

	cnt[src] += 1;

}
void dfsall(vector<int>*adjList, int n, int src, int parent)
{
	for (auto child : adjList[src])
	{
		if (child == parent)
			continue;
		dis[child] = dis[src] - cnt[child] + (n - cnt[child]) ;

		dfsall(adjList, n, child, src);
	}
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
{
	cnt.resize(n);
	dis.resize(n);
	vector<int>adjList[n];
	queue<int>q;
	for (int i = 0; i < edges.size() ; ++i)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// for (int i = 0; i < n ; ++i)
	// {
	// 	cout << i << " :";
	// 	for (auto val : adjList[i])
	// 		cout << val << " ";
	// 	cout << std::endl;
	// }
	dfs(adjList , 0, -1);  //bydefault considr src = 0 as rootnode
	dfsall(adjList, n, 0, -1);

	return dis;
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
		int n, e;
		cin >> n >> e;

		vector < vector<int>>edges;
		for (int i = 0; i < e; ++i)
		{
			int u, v;
			cin >> u >> v;
			vector<int>vec;
			vec.push_back(u);
			vec.push_back(v);
			edges.push_back(vec);
		}


		vector<int>v = sumOfDistancesInTree(n, edges);
	}
	for (auto val : dis)
		cout << val << " ";


	return 0;
}