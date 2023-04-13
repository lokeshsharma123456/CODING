#include<bits/stdc++.h>
using namespace std;
// SLIDING NOT APPIED HERE


#define ll long long int
int lenOfLongSubarr(int *a , int n, int k)
{
	int win_max = 0;
	int sum = 0;
	unordered_map<int, int>mp; //sum,index
	int j = 0;
	while (j < n)
	{
		sum += a[j];
		if (sum == k)
			win_max = j + 1;
		else
		{

			if (mp.find( sum) != mp.end())//if present
			{
				win_max = max(win_max , j - mp[sum]);
				// cout << sum << " ms:" << match_sum << " ,map:" << mp[sum] << " " << win_max << endl;
			}
			else
				mp[sum] = j;
		}
		j++;
	}

	// for (int i = beg; i <= end; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	return win_max;
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
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int k;
		cin >> k;
		cout << lenOfLongSubarr(arr, n, k) << std::endl;
	}

	return 0;
}