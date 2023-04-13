#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool isAlienSorted(vector<string>& words, string order)
{
	unordered_map<char, int>mp;
	for (int i = 0; i < order.length(); ++i)
	{
		mp[order[i]] = i;
	}

	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = i + 1; j < words.size(); ++j)
		{
			int k = 0;
			int len = min(words[i].length() , words[j].length());
			// cout << "comparing " << words[i] << " " << words[j] << endl;
			while (k < len)
			{
				if (mp[words[i][k]] > mp[words[j][k]])
					return false;
				else if (mp[words[i][k]] == mp[words[j][k]])
					k++;
				else if (mp[words[i][k]] < mp[words[j][k]])
					break;
			}
			if (k == len)
			{

				if (words[i].length()  > words[j].length())
					return false;
			}
		}
	}
	return true;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t;
	cin >> t;
	while (t--) {
		vector<string>v;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}
		string order;
		cin >> order;
		cout << (isAlienSorted(v, order) ? "true\n" : "false\n");
	}


	return 0;
}