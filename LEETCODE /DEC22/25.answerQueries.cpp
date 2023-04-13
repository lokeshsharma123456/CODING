#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
{
	int n = nums.size();
	// sort(nums.begin() , nums.end());
	vector<int>cs(n, 0);
	cs[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
		cs[i] = cs[i - 1] + nums[i] ;
	vector<int>ans;
	for (auto val : queries)
	{
		// cout << "val: " << val << " ";
		vector<int>::iterator lb = lower_bound(cs.begin(), cs.end(), val);
		int k = lb - cs.begin();
		if (k == n)//out of boundary
		{
			// cout << k << " ";
			// cout << "out of bound";
			ans.push_back(k);
		}
		else if (val < cs[k])
		{
			// cout << k << " ";

			ans.push_back(k);
		}
		else if (val >= cs[k])
		{
			// cout << k << " ";

			ans.push_back(k + 1);
		}
		else if (k == 0)
			ans.push_back(k);
		// cout << endl;
	}
	return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>nums, queries;
	for (int i = 0; i < n; ++i)
	{
		int k ;
		cin >> k;
		nums.push_back(k);
	}

	int q;
	cin >> q;

	while (q--)
	{
		int k;
		cin >> k;
		queries.push_back(k);
	}

	vector<int>v = answerQueries(nums, queries);
	for (auto val : v)
		cout << val << " ";


	return 0;
}