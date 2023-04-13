#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int helper(vector<int>&prices,  int index, int buyorSell, int **dp)
{
	if (index >= prices.size())
		return 0;

	if (dp[index][buyorSell] != -1)
		return dp[index][buyorSell];
	int a , b;

	if (buyorSell == 1)//buy karna hai
	{	//buy now two choices
		a = - prices[index] + helper(prices,  index + 1, 0, dp); //buy kar diya ab sell karna hoga
		b = 0 + helper(prices, index + 1, 1, dp); //buy nahi kiya

	}
	else if (buyorSell == 0 ) // ab bechega ya rukhega
	{
		a = prices[index] + helper(prices,   index + 2, 1, dp); //bechega to 1 din gap lega
		b = 0 + helper(prices, index + 1, 0, dp);//nahi becha

	}
	return dp[index][buyorSell] = max(a, b);


}
int maxProfit(vector<int>& prices)
{
	int profit = 0;
	int buyorSell = 1;
	int index = 0;
	//buy ==> 1 ,    sell==>0
	int n = prices.size();
	int **dp = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[2];
		for (int j = 0; j < 2; j++)
			dp[i][j] = -1;
	}
	int k = helper(prices,  index, buyorSell , dp);
	for (int i = 0; i < n; ++i)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return k;

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
		vector<int>v;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}

		cout << maxProfit(v) << endl;
	}
	return 0;
}