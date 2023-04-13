/*
You are given a directed graph of n nodes numbered from 0 to n - 1,
where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n,
 indicating that there is a directed edge from node i to node edges[i].
 If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2,
such that the maximum between the distance from node1 to that node, and from
node2 to that node is minimized. If there are multiple answers, return the
 node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from
node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot
 get a node with a smaller maximum distance than 1, so we return node 2.

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void dfs(vector<int>&edges, vector<bool>&isvisited, vector<int>&dis, int node)
{

	isvisited[node ] = true;
	int v = edges[node];

	if (v != -1 && !isvisited[v])
	{
		isvisited[v] = true;
		dis[v] = 1 + dis[node];
		dfs(edges, isvisited, dis, v);
	}

}

int closestMeetingNode(vector<int>& edges, int node1, int node2)
{
	int n  = edges.size();
	vector<int>dis_1(n , INT_MAX);
	vector<int>dis_2(n , INT_MAX);

	vector<bool>visted_1(n, false);
	vector<bool>visted_2(n, false);

	dis_1[node1] = 0;
	dis_2[node2] = 0;

	dfs(edges, visted_1, dis_1, node1);
	dfs(edges, visted_2, dis_2, node2);

	int minDistanceNode = -1;
	int minDisTillNow = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		int maxDistanceBetween = max(dis_1[i], dis_2[i]);
		if (minDisTillNow > maxDistanceBetween)
		{
			minDisTillNow = maxDistanceBetween;
			minDistanceNode = i;
		}
	}

	return minDistanceNode;
}




int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> edges;
	while (n--) {
		int k;
		cin >> k;
		edges.push_back(k);
	}
	int n1, n2;
	cin >> n1 >> n2;
	cout << closestMeetingNode(edges, n1, n2) << endl;


	return 0;
}