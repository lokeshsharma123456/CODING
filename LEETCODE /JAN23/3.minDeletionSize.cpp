#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int minDeletionSize(vector<string>& strs)
{
	int r = strs.size();
	int c = strs[0].size();
	int cnt = 0;
	for (int i = 0; i < c; ++i)
	{
		char c = 'A';
		for (int j = 0; j < r; j++)
		{
			if (c > strs[j][i])
			{
				// cout << c << "  " << strs[j][i] << endl;
				cnt++ ;
				break;
			}
			else
				c = max(c, strs[j][i]);

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
	vector<string> strs;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		strs.push_back(s);
	}
	cout << minDeletionSize(strs) << endl;


	return 0;
}
