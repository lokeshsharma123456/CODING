#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i;
	char c;
	int t = 100;
	vector<int>v;

	while (t--)
	{
		cin >> i;
		if (i == -1)
			break;
		v.push_back(i);
	}
	cout << v.size();


	return 0;
}