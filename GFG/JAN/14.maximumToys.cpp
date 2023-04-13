#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int temp = 50;
vector<int> maximumToys(int n, vector<int> arr, int Q, vector<vector<int>> Queries)
{
	vector<int>ans;
	unordered_map<int, int>mp_broken;
	for (int q = 0; q < Q; q++)
	{

		int cost = Queries[q][0];
		int broken = Queries[q][1];
		for (int i = 0; i < broken; ++i)
		{
			mp_broken[Queries[q][i + 2] - 1] ++;
			// arr[Queries[q][i + 2] - 1] = INT_MAX;
		}

		int i = 0;
		int j = i;
		int mxtoys = 0;
		while (i < arr.size())
		{
			if (mp_broken.find(i) != mp_broken.end())
				i++;//broken
			int cur_sum = cost;
			int cnt = 0;
			j = i;
			// cout << "i:" << i << "  j:" << j << endl;
			while (j < arr.size())
			{
				// if (--temp < 0)
				// 	exit(0);
				if (mp_broken.find(j) != mp_broken.end())
					j++;//broken
				else
				{
					cur_sum -= arr[j];//calculation
					// cout << "cur_sum:" << cur_sum << " j:" << j << endl;
					//1. condition less
					if (cur_sum >= 0)
					{
						cnt++;
						j++;
						mxtoys = max(cnt, mxtoys);
						// cout << mxtoys << endl;
					}
					else if (cur_sum < 0)
					{
						// cout << j << "hi:" << endl;
						i++;
						// cout << i << " ";
						j = arr.size() + 222;
					}
				}
			}
			if (j == arr.size())
			{
				ans.push_back(mxtoys);
				break;
			}
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
	int n;
	cin >> n;
	vector<int>arr;
	vector<vector<int>> Queries;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int x;
		cin >> x;
		vector<int>v;
		while (x--)
		{
			int k;
			cin >> k;
			v.push_back(k);
		}
		Queries.push_back(v);
	}
	// cout << "cost : " << Queries[0][0] << endl;
	// cout << "k : " << Queries[0][1] << endl;
	// cout << "ind1 : " << Queries[0][2] << endl;
	// cout << "ind2 : " << Queries[0][3] << endl;
	vector<int>v = maximumToys(n, arr, q, Queries);
	for (auto val : v)
	{
		cout << val << " ";
	}


	return 0;
}