#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int lcs(string text1 , string text2)
{
	int n = text1.size() + 1;
	int m = text2.size() + 1;
	int dp[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (text1[i - 1] == text2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	return dp[n - 1][m - 1];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	cout << lcs(a, b);


	return 0;
}