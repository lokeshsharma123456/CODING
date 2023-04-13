#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int ans = INT_MAX;
// void helper(vector<int>& v, int days, int i, int sum, int current_min)
// {
// 	// cout << i << " " << sum << " " << days << " " << current_min << endl;
// 	if (days < 0 )
// 	{
// 		return;
// 	}
// 	if (i == v.size() && days >= 0)
// 	{
// 		cout << "s:" << sum << " i:" << i << " ans:" << ans << " cm:" << current_min  << endl << endl;
// 		ans = min(current_min, ans);
// 		return;
// 	}
// 	if (i >= v.size())
// 		return;


// 	while (i < v.size() && sum + v[i] <= current_min)
// 		sum += v[i++];
// 	if (i < v.size() && sum + v[i] >= current_min)
// 	{
// 		helper(v, days - 1, i + 1, v[i], current_min);//chota rhne diya
// 		helper(v, days - 1, i + 1, 0, sum + v[i]);//bda bna
// 	}
// 	return ;
// }
bool isPossible(vector<int>& weights, int mid, int days)
{
	int d = 1;
	int sum = 0;
	for (int i = 0; i < weights.size(); ++i)
	{
		sum += weights[i];
		if (sum > mid)
		{
			d++;
			sum = weights[i];
		}
	}
	return d <= days;
}
int shipWithinDays(vector<int>& weights, int days)
{
	int sum = 0;
	int mx = INT_MIN;

	for (int i = 0; i < weights.size(); ++i)
	{
		mx = max(mn, weights[i]);
		sum += weights[i];
	}
	if (weights.size() == days)
		return mx;
	int low  = mx;
	int high = sum;
	int ans = 0;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if ( isPossible(weights, mid, days))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mi + 1;
		}
	}
	return ans;
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
	int days ;
	cin >> days;
	cout << shipWithinDays(v, days) << endl;
	return 0;
}