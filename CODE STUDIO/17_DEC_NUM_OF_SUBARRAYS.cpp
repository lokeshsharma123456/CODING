#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int calc(int v)
{
	int mul = 0;
	int st = 1;
	// cout  << v ;
	while (v)
	{
		mul += st++ ;
		v--;
	}
	// cout << " ,mul:" << mul << endl;
	return mul;
}
int numberofSubarrays(vector<int> & arr, int n)
{
	int sum = 0;
	vector<int>check;
	int index_check = 0;
	check.push_back(1);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] == arr[i - 1])
		{
			check[index_check]++;
		}
		else
		{
			check.push_back(1);
			index_check++;
		}

	}
	for (auto x : check)
		sum += calc(x);
	return sum;
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
		vector<int>v;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		cout << numberofSubarrays(v, n) << "\n\n\n";
	}

	// cout << calc(4);
	return 0;
}