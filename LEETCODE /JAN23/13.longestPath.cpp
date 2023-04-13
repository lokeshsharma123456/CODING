#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int total_max = 1;
int dfs(vector<vector<int>>adj, string &s, int node)
{
	if (adj[node].size() == 0)
		return 1;
	int longest = 0, sec_long = 0;
	for (auto child : adj[node])
	{

		int val_frm_child = dfs(adj, s, child);
		total_max = max(val_frm_child, total_max);
		if (s[child] == s[node])
			continue;
		if (val_frm_child > sec_long)
			sec_long = val_frm_child;

		if (sec_long > longest)
			swap(longest, sec_long);
		// cout << node << " " << child << " " << longest << " " << sec_long << endl;
	}


	int eq1 = 1 + longest + sec_long;
	int eq2 = 1 + longest;
	// cout << eq1 << " " << eq2 << endl;

	total_max = max(eq1, total_max);
	return eq2;

}
int longestPath(vector<int>& parent, string &s)
{
	vector<vector<int>>v(parent.size());
	for (int i = 0; i < parent.size(); ++i)
	{
		if (i == 0)
			continue;

		v[parent[i]].push_back(i);
	}
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << i << ": ";
	// 	for (auto val : v[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }
	int k = dfs(v, s, 0);
	return total_max;

}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		/* code */
		int n;
		cin >> n;
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		string s;
		cin.get();
		cin >> s;
		cout << longestPath(v, s) << endl;
	}

	return 0;
}