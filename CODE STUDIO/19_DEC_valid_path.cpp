#include<bits/stdc++.h>
using namespace std;

#define ll long long int
bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
	queue<int>q;
	q.push(source);
	int isVisted[n];
	for (int i = 0; i < n; ++i)
		isVisted[i] = 0;
	while (q.size())
	{
		int f = q.front();
		q.pop();
		cout << "cur_node:" << f;
		if (!isVisted[f])
		{
			isVisted[f] = 1;
			for (int i = 0; i < edges[f].size(); ++i)
			{
				cout << " , connected:" << edges[f][i];
				if (edges[f][i] == destination)
					return true;
				if (!isVisted[edges[f][i]])
					q.push(edges[f][i] );
			}
		}
		cout << " " << std::endl;
	}
	return false;
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
	edges.resize(n);
	for (int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s, d;
	cin >> s >> d;
	cout << ( validPath(n , edges , s , d) ? "\ntrue\n" : "\nfalse\n");



	return 0;
}