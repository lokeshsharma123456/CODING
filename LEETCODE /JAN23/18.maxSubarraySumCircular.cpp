#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int maxSubarraySumCircular(vector<int>& nums)
{
	int n = nums.size();
	int sum = 0;
	int maxSum = INT_MIN;

	int arrSum = 0;
	for (auto val : nums)
		arrSum += val;
	// cout << arrSum << endl;

	for (int i = 0; i < n; ++i)
	{
		sum += nums[i]  ;
		maxSum = max(sum, maxSum);
		// cout << i << " " << sum << " " << maxSum  << endl;
		if (sum < 0)
			sum = 0;
	}

	//doing all -1 then find
	for (int i = 0; i < n; ++i)
		nums[i] *= -1;

	sum = 0;
	int maxSum1 = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		sum += nums[i]  ;
		maxSum1 = max(sum, maxSum1);
		// cout << i << " " << sum << " " << maxSum1  << endl;
		if (sum < 0)
			sum = 0;
	}
	// cout << maxSum1 << endl;
	if (arrSum + maxSum1 == 0)
		return maxSum;

	return max(maxSum, arrSum + maxSum1);
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

		std::vector<int> v;
		int n;
		cin >> n;
		while (n--) {
			int k;
			cin >> k;
			v.push_back(k);
		}
		cout << maxSubarraySumCircular(v) << endl;
	}


	return 0;
}