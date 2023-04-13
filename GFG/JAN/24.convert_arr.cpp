#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void convert(int arr[], int n)
{
	// code here
	vector<int>v;
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++)
		v.push_back(arr[i]);

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		mp[v[i]] = i;


	for (int i = 0; i < n; i++)
		arr[i] = mp[arr[i]];

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	convert(arr , n);


	return 0;
}