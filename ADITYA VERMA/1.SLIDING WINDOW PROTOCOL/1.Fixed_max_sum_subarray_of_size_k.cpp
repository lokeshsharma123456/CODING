/*
Given an integer array nums,
 find the subarray which has the largest sum and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

[-2,-1]
output = -1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
long max_sum_subarray_K(vector<int>&v, int k)
{
	int n = v.size();
	long cs = 0 , sum = 0;
	for (int i = 0; i < k; ++i)
		cs += v[i];
	sum = max(sum, cs);
	int j = 0;
	for (int i = k; i < n; ++i)
	{
		cs += v[i] - v[j++];
		sum = max(sum , cs);
	}

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
		int n;
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		int k;
		cin >> k;
		cout << max_sum_subarray_K(v, k) ;

	}


	return 0;
}