#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int val = -1;
void helper(vector<int>n, int b, int e)
{
	if (b == e)
	{
		val = n[b];
		return ;
	}
	int mid = (b + e) / 2;
	if (mid % 2 == 1)
	{
		if (0 < mid && n[mid] == n[mid - 1])
		{
			b = mid + 1;
			helper(n, b, e);
		}
		else
		{
			e = mid - 1;
			helper(n, b, e);
		}
	}
	else if (mid % 2 == 0)
	{
		if ( mid < e && n[mid] == n[mid + 1])
		{
			b = mid + 1;
			helper(n, b, e);
		}
		else
		{
			e = mid - 1;
			helper(n, b, e);
		}
	}

}
int singleNonDuplicate(vector<int>v)
{
	int b = 0;
	int e = v.size() - 1;
	helper(v, b, e);
	return val;
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
	cout << singleNonDuplicate(v);

	return 0;
}