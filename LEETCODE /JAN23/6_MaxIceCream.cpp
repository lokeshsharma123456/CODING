#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int maxIceCream(vector<int>& costs, int coins)
{
	sort(costs.begin(), costs.end());
	int cnt = 0;
	for (int i = 0; i < costs.size(); ++i)
	{
		if (costs[i] <= coins)
		{
			cnt++;
			coins -= costs[i];
			if (coins < 0)
				return cnt;
		}
	}
	return cnt;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>costs;
	int coins;
	int n;
	cin >> n;
	while (1) {
		int k;
		cin >> k;
		if (k == -1)
			break;
		costs.push_back(k);
	}
	cin >> coins;
	cout << maxIceCream(costs, coins) << endl;

	return 0;
}