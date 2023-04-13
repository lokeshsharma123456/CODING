#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int maxIntersections(vector<vector<int>>&lines, int n)
{
	std::map<int, int> mp;
	for (auto val : lines)
	{
		int s = val[0];
		int e = val[1];
		mp[s]++;
		mp[e + 1]--;
	}
	int ans = 1;
	int sum = 0;
	for (auto it : mp)
	{
		sum += it.second;
		ans = max(ans, sum);
	}

	return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	vector<vector<int>> lines;

	while (t--)
	{
		int b, e;
		cin >> b >> e;
		vector<int>v;
		v.push_back(b);
		v.push_back(e);
		lines.push_back(v);
	}

	cout << maxIntersections(lines, t);
	return 0;
}