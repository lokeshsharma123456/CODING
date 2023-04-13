#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int rob(vector<int>&nums)
{
	if (nums.size() == 1)
		return nums[0];

	if (nums.size() > 2)
	{
		int vec_size = nums.size() - 1;
		nums[vec_size - 1] = max(nums[vec_size], nums[vec_size - 1]);

		for (int i = vec_size - 2; i >= 0; i--)
		{
			nums[i] = max(nums[i + 1], nums[i] + nums[i + 2]);
		}
	}
	return max(nums[0], nums[1]);
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