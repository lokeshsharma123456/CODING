#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{

	int new_start = newInterval[0];
	int new_end = newInterval[1];
	int n = intervals.size();
	vector<vector<int>> v;

	// strarting k vectors
	for (int i = 0; i < n; ++i)
	{
		if (intervals[i][1] < new_start)
			v.push_back(intervals[i]);
	}



	//beech ka intervals

	for (int i = 0; i < n; ++i)
	{
		if (new_start <= intervals[i][0] && intervals[i][0] <= new_end  ||
		        new_start <= intervals[i][1] && intervals[i][1] <= new_end ||
		        intervals[i][0] <= new_start && new_end <= intervals[i][1]   )
		{
			new_start = min(intervals[i][0] ,  new_start);
			new_end = max(intervals[i][1] ,  new_end);
		}
	}
	vector<int>k;
	k.push_back(new_start);
	k.push_back(new_end);
	v.push_back(k);

	//end ka saman
	for (int i = 0; i < n; ++i)
	{
		if (new_end < intervals[i][0])
			v.push_back(intervals[i]);
	}

	return v;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	vector<vector<int>>v;
	sort(intervals.begin(), intervals.end());

	int n = intervals.size();
	if (intervals.size() == 0)
		return v;
	int i = 0;
	int si = intervals[i][0];
	int ei = intervals[i][1];
	i++;
	while (i < n)
	{
		// si = intervals[i][0];
		// ei = intervals[i][1];
		if (si <= intervals[i][0] && intervals[i][0] <= ei  ||
		        si <= intervals[i][1] && intervals[i][1] <= ei  ||
		        si <= intervals[i][0] && intervals[i][1] <= ei )
		{

			si = min(intervals[i][0], si);
			ei = max(intervals[i][1], ei);
			i++;
			// cout << si << " " << ei << endl;;
		}
		else if (ei < intervals[i][0] )
		{
			vector<int>k;
			k.push_back(si);
			k.push_back(ei);
			v.push_back(k);

			si = intervals[i][0];
			ei = intervals[i][1];
			i++;
		}
	}
	vector<int>k;
	k.push_back(si);
	k.push_back(ei);
	v.push_back(k);

	return v;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>> intervals;
	vector<int> newInterval;
	int n ;
	cin >> n;
	while (n--)
	{
		vector<int>k;
		int a, b;
		cin >> a >> b;
		k.push_back(a);
		k.push_back(b);
		intervals.push_back(k);
	}
	n = 2;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		newInterval.push_back(a);
		newInterval.push_back(b);
	}

	// vector<vector<int>> v = insert(intervals, newInterval);
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	for (auto val : v[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }
	vector<vector<int>> v = merge(intervals);
	for (int i = 0; i < v.size(); ++i)
	{
		for (auto val : v[i])
			cout << val << " ";
		cout << endl;
	}


	return 0;
}

