#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int calc(vector<int> dif, int n)
{
	int i = n;
	int s = dif.size();
	int flag = 0;
	int sum = 0;
	while (1)
	{
		if (flag)
		{
			if (i % s == n)
				return n;
		}
		flag = 1;
		sum += dif[i++];
		if (sum < 0)
			return -1;

	}
}

int firstCircularTour(vector<int> &petrol, vector<int> &distance, int n)
{
	if (accumulate(petrol.begin(), petrol.end(), 0) < accumulate(distance.begin(), distance.end(), 0))
		return -1;
	vector<int>dif;
	for (int i = 0; i < petrol.size(); ++i)
		dif.push_back(petrol[i] - distance[i]);

	// for (auto val : dif)
	// 	cout << val << " ";
	// cout << endl;

	for (int i = 0; i < petrol.size(); ++i)
		if (dif[i] >= 0)
		{
			int k = calc(dif , i);
			if (k >= 0)
				return k;
		}
	return -1;
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
		vector<int>petrol, distance;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int p, d;
			cin >> p >> d;
			petrol.push_back(p);
			distance.push_back(d);

		}
		cout << firstCircularTour(petrol, distance, n) << endl;
	}


	return 0;
}