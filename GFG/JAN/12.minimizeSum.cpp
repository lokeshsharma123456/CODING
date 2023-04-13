#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int minimizeSum(int n, vector<int> arr)
{
	priority_queue<int>pq;
	for (auto val : arr)
		pq.push(-1 * val);
	int sum = 0;
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		sum += -1 * (a + b);
		pq.push(a + b);
	}
	return sum;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	cout << minimizeSum(n, v) << endl;


	return 0;
}