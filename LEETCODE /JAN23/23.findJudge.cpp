#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int findJudge(int n, vector<vector<int>>& trust)
{
	int arr[n + 1][2];
	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < 2; j++)
			arr[i][j] = 0;

	for (int i = 0; i < trust.size(); ++i)
	{
		int num_of_people_it_trusts = trust[i][0];
		int num_of_people_trusts_him = trust[i][1];

		arr[num_of_people_it_trusts][0]++;
		arr[num_of_people_trusts_him][1]++;
	}



	// for (int i = 0; i < n + 1; ++i)
	// 	for (int j = 0; j < 2; j++)
	// 		cout << arr[i][j] << " ";

	for (int i = 0; i < n + 1; ++i)
	{
		if (arr[i][0] == 0 && arr[i][1] == n - 1)
		{
			return i;
		}
	}

	return -1;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int e;
	cin >> e;
	vector<vector<int>>trust;
	for (int i = 0; i < e; ++i)
	{
		vector<int>k;
		int a, b;
		cin >> a >> b;
		k.push_back(a);
		k.push_back(b);
		trust.push_back(k);
	}
	cout << findJudge(n, trust) << endl;
	return 0;
}

