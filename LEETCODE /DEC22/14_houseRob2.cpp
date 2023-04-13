/*You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are
arranged in a circle. That means the first house is the neighbor of the last one.
 Meanwhile, adjacent houses have a security system connected, and it will automatically
 contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int rob(vector<int>&nums)
{
	vector<int>v;
	v = nums;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);

	int k;
	if (nums.size() > 2)
	{
		//nums vale me num[0]............num[n-2]
		int vec_size = nums.size() - 2;
		nums[vec_size - 1] = max(nums[vec_size], nums[vec_size - 1]);

		for (int i = vec_size - 2; i >= 0; i--)
		{
			nums[i] = max(nums[i + 1], nums[i] + nums[i + 2]);
		}

		int nums_max = max(nums[0], nums[1]);

		//v vale me num[1]...............num[n-1]tak
		vec_size = nums.size() - 1;
		v[vec_size - 1] = max(v[vec_size], v[vec_size - 1]);
		for (int i = vec_size - 2; i > 0; i--)
		{
			v[i] = max(v[i + 1], v[i] + v[i + 2]);
		}

		int v_max = max(v[2], v[1]);
		k = max(v_max , nums_max);
	}
	return k;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>m;
	for (int j = 0; j < n; j++)
	{
		int k;
		cin >> k;
		m.push_back(k);
	}

	cout << rob(m) << endl;
	return 0;
}