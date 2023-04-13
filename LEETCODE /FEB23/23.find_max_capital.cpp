#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int temp = 100;
int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c)
{
	priority_queue<pair<int, int>>pq;
	int i = 0 ;
	long long int sum = w;
	vector<pair<int, int>>v;
	for (int i = 0; i < p.size(); ++i)
	{
		v.push_back({c[i], p[i]});
	}

	sort(v.begin(), v.end());
	while (k > 0 && i < v.size())
	{
		while (i < v.size() && sum >= v[i].first)
		{
			int c = v[i].first;
			int p = v[i].second;
			pq.push({p, c});
			i++;
		}
		if (!pq.empty())
		{
			auto m = pq.top();
			// cout << pq.top().first << endl;
			pq.pop();
			sum += m.first;
			// cout << "w:" << w << endl;
		}
		k--;

	}
	// cout << "k" << k << endl;

	while (k > 0 && !pq.empty())
	{
		auto m = pq.top();
		int p = m.first;
		int c = m.second;
		pq.pop();
		sum += p ;
		k--;
	}

	return sum;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>p;
	vector<int>c;
	int k;
	int w;
	while (1) {
		int a;
		cin >> a;
		if (a == -1)
			break;
		p.push_back(a);
	}
	while (1) {
		int a;
		cin >> a;
		if (a == -1)
			break;
		c.push_back(a);
	}
	cin >> k >> w;

	cout << findMaximizedCapital(k, w, p, c);


	return 0;
}