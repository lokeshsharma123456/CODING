#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int minimumRounds(vector<int>& tasks)
{
	int maxi = 0;
	int n = tasks.size();
	unordered_map<int, int>mp;
	for (int i = 0; i < n; ++i)
	{
		mp[tasks[i]]++;
		maxi = max(maxi, mp[tasks[i]]);
	}
	cout << maxi << endl;
	int dp[maxi + 1];
	dp[0] = 1;
	dp[1] = 10000;
	if (maxi > 1)
		dp[2] = 1;
	if (maxi > 2)
		dp[3] = 1;
	for (int i = 4; i <= maxi; i++)
	{
		dp[i] = 1 + min(dp[i - 2] , dp[i - 3]);
		cout << "hi:" << dp[i] << endl;
	}
	// for (auto val : dp)
	// 	cout << val << " ";
	// cout << endl;
	int cnt = 0;
	for (auto it : mp)
	{
		cout << it.first << " " << it.second << endl;
		if (it.second == 1)
			return -1;
		cnt += dp[it.second];
	}

	return cnt;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>tasks;
	while (n--)
	{
		int k;
		cin >> k;
		tasks.push_back(k);
	}
	cout << minimumRounds(tasks) << endl;

	return 0;
}