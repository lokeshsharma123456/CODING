#include<bits/stdc++.h>
using namespace std;

#define ll long long int

string frequency_sort(string s)
{
	string str = "";
	unordered_map<char, int>mp;
	for (int i = 0; i < s.length(); ++i)
	{
		if (mp[s[i]] == 0)
			mp[s[i]] = 1;
		else
			mp[s[i]]++;

	}
	vector<pair<int, char>>v;
	for (auto it : mp)
	{
		v.push_back(make_pair(it.second, it.first));
	}
	sort(v.rbegin() , v.rend());
	for (auto it : v)
	{
		int k = it.first;
		while (k--)
			str += it.second;
	}

	return str;
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
		string n;
		cin >> n;
		cout << frequency_sort(n) << "\n";

	}







	return 0;
}