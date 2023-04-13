#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
{
	vector<int>dif(rocks.size(), 0);
	for (int i = 0; i < rocks.size(); ++i)
		dif[i] = capacity[i]  - rocks[i];

	sort(dif.begin(), dif.end());
	int cnt = 0;
	for (auto val : dif)
		cout << val << " ";
	cout << endl;
	for (int i = 0; i < rocks.size(); ++i)
	{
		if (dif[i] == 0)
			cnt++;
		else if (dif[i] > additionalRocks)
			break;
		else
		{
			cnt++;
			additionalRocks -= dif[i];
		}
	}
	return cnt;
}


int minStoneSum(vector<int>& piles, int k)
{
	int cs = 0;
	priority_queue<int>pq;
	for (auto val : piles)
	{
		cs += val;
		pq.push(val);
	}
	// cout << endl;
	while (k > 0)
	{
		int temp = pq.top() / 2 + pq.top() % 2;
		cs = cs - pq.top() +  temp;
		pq.pop();
		pq.push(temp);
		k--;
	}

	return cs;

}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	// vector<int>rocks, capacity;
	// int additionalRocks;
	// for (int i = 0; i < n; ++i)
	// {
	// 	int k;
	// 	cin >> k;
	// 	capacity.push_back(k);
	// }
	// for (int i = 0; i < n; ++i)
	// {
	// 	int k;
	// 	cin >> k;
	// 	rocks.push_back(k);
	// }
	// cin >> additionalRocks;

	// cout << maximumBags(capacity, rocks, additionalRocks);
	vector<int>piles;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		piles.push_back(k);
	}
	int k;
	cin >> k;
	cout << minStoneSum(piles , k);

	return 0;
}