#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int maxWeightCell(int n, vector<int> edge)
{
	priority_queue<pair<int, int>>pq;
	unordered_map<int, int>mp;
	for (int i = 0; i < n; ++i)
		if (edge[i] != -1)
			mp[edge[i]]++;
	if (mp.size() == 0)
		return 0;
	int cnt = 0;
	int index = 0;
	for (auto val : mp)
	{
		if (cnt < val.second)
		{
			cnt = val.second;
			index = val.first;
		}
		else if (cnt == val.second)
		{
			index = max(index , val.first);
		}
	}
	return index;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>edge;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		edge.push_back(k);
	}
	cout << maxWeightCell(n, edge) << endl;

	return 0;
}