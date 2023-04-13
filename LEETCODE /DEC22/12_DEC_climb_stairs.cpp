#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int climbstairs(int n)
{

	int dp[n + 1] ;
	for (int i = 3; i < n + 1; ++i)
		dp[i] = 0;
	dp[0] = 1;
	dp[1] = 1;
	if (n > 1)
	{
		dp[2] = 2;
		for (int i = 3; i < n + 1; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[n];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << climbstairs(n) << endl;


	return 0;
}