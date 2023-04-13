#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll n;
vector<long long> printFirstNegativeInteger(ll a[], ll n, ll k)
{
	vector<long long>v;
	int i = 0 , j = 0;
	queue<int>q;

	while (j < n)
	{
		if (a[j] < 0)
			q.push(a[j]);
		if (j - i + 1 < k)
		{
			j++;
		}
		else if (j - i + 1 == k)
		{

			// cout << "\n full: i=" << i << " ," << a[i] << " j=" << j << " ," << a[j] << endl;
			if (q.empty())
				v.push_back(0);
			else
			{
				if (a[i] == q.front())
				{
					v.push_back(q.front());
					q.pop();
				}
				else {
					v.push_back(q.front());
				}
			}
			i++;
			j++;
		}
	}
	return v;

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

		ll n;
		cin >> n;
		ll a[n];
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		ll k;
		cin >> k;
		vector<long long>v = printFirstNegativeInteger(a, n, k);
		for (auto val : v)
			cout << val << " ";
		cout << endl;
	}


	return 0;
}