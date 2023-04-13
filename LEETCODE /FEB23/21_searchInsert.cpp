#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int ind = 0;
void helper(vector<int>& n, int target, int b, int e)
{
	cout << "b:" << b << "," << n[b] << "  e:" << e << "," << n[e] << endl;
	if (n[e] < target)
	{
		ind = e + 1;
		return;
	}
	if (n[b] > target)
	{
		ind = b;
		return;
	}

	int mid = (e + b) / 2;
	if (n[mid] == target)
	{
		ind = mid;
		return;
	}
	else if (n[mid] > target)
	{
		e = mid - 1;
		// if (e > b)
		helper(n, target, b, e);
	}
	else if (n[mid] < target)
	{
		b = mid + 1;
		// if (b < e)
		helper(n, target, b, e);
	}
}
int searchInsert(vector<int>& nums, int target)
{
	int beg = 0;
	int end = nums.size() - 1;
	helper(nums, target, beg, end);
	return ind;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::vector<int> v;
	while (1) {
		int k;
		cin >> k;
		if (k == -1)
			break;
		v.push_back(k);
	}
	int target;
	cin >> target;

	cout << searchInsert(v, target) << endl;


	return 0;
}