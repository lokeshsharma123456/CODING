#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define par_to_y -999
#define par_to_x 0
int maxPoints(vector<vector<int>>& points)
{
	float intercept;
	int curr_max = 0;
	int per_point_max = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		unordered_map<float, int>mp;
		int x1 = points[i][0];
		int y1 = points[i][1];
		for (int j = 0; j < points.size(); ++j)
		{
			if (i == j)
				continue;
			int x2 = points[j][0];
			int y2 = points[j][1];

			if (x2 == x1)
			{
				mp[par_to_y]++;
				curr_max = max(mp[par_to_y] , curr_max);
			}
			else if (y2 == y1)
			{
				mp[par_to_x]++;
				curr_max = max(mp[par_to_x] , curr_max);
			}
			else
			{
				// cout << "x1:" << x1 << " " << "x2:" << x2 << " ";
				// cout << "x1:" << y1 << " " << "x2:" << y2 << " " << endl;
				intercept = (float)(y2 - y1) / ((float)(x2 - x1));
				mp[intercept]++;
				curr_max = max(mp[intercept] , curr_max);
				// cout << intercept << endl;
			}
		}
		// for (auto v : mp)
		// 	cout << v.first << " " << v.second << endl;
		// cout << endl;
		per_point_max = max(curr_max, per_point_max);
	}
	return per_point_max + 1;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector < vector<int>>points;
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		vector<int>v;
		v.push_back(a);
		v.push_back(b);
		points.push_back(v);
	}
	cout << maxPoints(points) << endl;


	return 0;
}