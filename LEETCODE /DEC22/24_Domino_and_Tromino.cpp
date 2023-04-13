#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M (1000000000 + 7)

int numTilings(int n) {
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = ((2 * dp[i - 1]) % M + dp[i - 3]) % M;
	}
	return dp[n];
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

		int n;
		cin >> n;
		cout << numTilings(n) << endl;
	}


	return 0;
}