#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void print(vector<int>&v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}
int helper(vector<int>&nums , vector<ll>&cs , int index)
{
	int n = nums.size();
	int a = cs[index] / (index + 1) ;
	int rem = (n - index - 1);

	int b = (cs[n - 1] - cs[index]);
	if (b)
		return abs(a - (b / rem));
	else
		return a;
}

int  minimumAverageDifference(vector<int>&nums)
{
	vector<ll>cs;
	// long long int * cs = new ll[nums.size()];
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0)
			cs.push_back(nums[i]);
		else
			cs.push_back( cs[i - 1] + nums[i]);

	}
	int minVAl = INT_MAX;
	int index  = 0;
	for (int i = 0; i < nums.size() ; ++i)
	{
		int k = helper(nums , cs , i);
		if (k < minVAl)
		{
			minVAl = k;
			index = i;
		}
	}
	return index;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t;

	// cin >> t;
	// while (t--)
	// {

	int n;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		// cout << " him\n";
		v.push_back(k);
		// std::cout << v[i] << endl;
	}
	// cout << " hi\n";
	cout <<  minimumAverageDifference(v) << std::endl;

	// }




	return 0;
}