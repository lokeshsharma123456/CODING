#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int subarraysDivByK(vector<int>& nums, int k)
{
	unordered_map<int, int>mp;
	mp[0] = 1;
	int cnt = 0;
	int cs = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		cs += nums[i];
		int rem = cs % k;
		if (rem < 0)
			rem = rem + k;
		if (mp.find(rem) != mp.end()) //if exist in map
		{
			cnt += mp[rem];
			mp[rem]++;
		}
		else
			mp[rem]++;
	}


	return cnt;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	std::vector<int> v;

	while (n--)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	int k;
	cin >> k;
	cout << subarraysDivByK(v, k) << endl;

	return 0;
}