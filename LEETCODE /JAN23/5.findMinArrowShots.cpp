#include<bits/stdc++.h>
using namespace std;

#define ll long long int
static bool comp(vector<int>&a, vector<int>&b)
{
	if (a[1] < b[1])
		return a[1] < b[1];
	else if (a[1] == b[1])
		return a[0] < b[0];

	return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& points)
{

	sort(points.begin(), points.end(), comp);
	// for(int i=0; i<points.size(); i++)
	// {

	// }
	// for (int i = 0; i < points.size(); ++i)
	// {
	// 	for (auto val : points[i])
	// 		cout << val << " ";
	// 	cout << endl;
	// }
	int cnt = 1;
	int cur_end = points[0][1];
	for (int i = 1; i < points.size(); ++i)
	{
		if (cur_end >= points[i][0])
			continue;
		else
		{
			cnt++;
			cur_end = points[i][1];
		}
	}
	return cnt;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<vector<int>>points;
	while (n--)
	{
		int i, j;
		cin >> i >> j;
		vector<int>v;
		v.push_back(i);
		v.push_back(j);
		points.push_back(v);
	}
	cout << findMinArrowShots(points) << std::endl;


	return 0;
}