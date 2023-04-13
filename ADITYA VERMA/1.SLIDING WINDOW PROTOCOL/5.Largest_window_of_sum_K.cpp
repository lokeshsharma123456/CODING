#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int lenOfLongSubarr(int *a , int n, int k)
{
	int i = 0, j = 0;
	int win_max = 0;
	int sum = 0;
	while (j < n && i <= j)
	{
		sum += a[j];
		cout << sum << ", i:" << i << " , j:" << j << endl;
		if (sum < k)
		{
			j++;
		}
		else if (sum == k)
		{
			win_max = max(win_max , j - i + 1);
			j++;
		}
		else if (sum > k)
		{
			while (sum > k)
			{
				sum -= a[i];
				i++;
			}
			j++;
		}
	}
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