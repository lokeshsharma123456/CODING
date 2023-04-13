#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int ans = 0;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
	vector<int>distance(n, INT_MAX);

	unordered_map<int , vector<pair<int, int>> > adj;

	for (vector<int> &vec : flights)
	{
		int s = vec[0];
		int d = vec[1];
		int c = vec[2];

		adj[s].push_back({d, c});
	}


	queue<pair<int, int>>q;
	q.push({src , 0});
	distance[src] = 0;
	int steps = 0;

	while (q.size() && steps <= k)
	{
		int N = q.size() ;// current level k sare node ko process karte hin

		while (N--)
		{
			auto x = q.front();
			q.pop();
			int u = x.first;
			int abhi_tk_src_ki_dis = x.second;

			for (pair<int, int> vec : adj[u])
			{
				int v = vec.first;
				int adj_node_of_s_ki_dis = vec.second;
				//v tak pahunch nne ki distance dekho
				if (distance[v] > abhi_tk_src_ki_dis + adj_node_of_s_ki_dis)
				{
					distance[v] = abhi_tk_src_ki_dis + adj_node_of_s_ki_dis;
					q.push({v, distance[v]});
				}
			}
		}
		steps++;
	}

	if (distance[dst] == INT_MAX)
		return -1;
	else
		return distance[dst];

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

	vector<int>v;


	int s, d, cost;
	vector<vector<int>> flights;
	for (int i = 0; i < e; ++i)
	{
		cin >> s >> d >> cost;
		v.push_back(s);
		v.push_back(d);
		v.push_back(cost);
		flights.push_back(v);

	}
	cin >> s >> d >> cost;
	cout << findCheapestPrice(n, flights, s, d, cost) << endl;




	return 0;
}