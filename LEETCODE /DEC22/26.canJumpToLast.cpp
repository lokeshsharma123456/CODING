#include<bits/stdc++.h>
using namespace std;

#define ll long long int
bool canJump(vector<int>& nums)
{
	int n = nums.size();
	vector<bool> check(n, false);
	check[n - 1] = true;
	int i = n - 2;
	while (i >= 0)
	{
		int k = nums[i];
		while (k)
		{
			if (i + k == n - 1 || (i + k < n) && check[i + k] == true)
			{
				check[i] = true;
				break;
			}
			k--;
		}
		i--;
	}
	// for (auto val : check)
	// 	cout << val << " ";
	return check[0];

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
		vector<int>nums;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			nums.push_back(k);
		}
		cout << (canJump(nums) ? "true\n" : "false\n");
	}


	return 0;
}
