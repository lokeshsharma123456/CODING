/*
Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest
substring with K distinct characters.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int longestKSubstr(string s, int k)
{
	unordered_map<char, int>mp;
	int i = 0,  j = 0;
	int window_size = -1;
	while (j < s.size())
	{
		//1.calculation
		mp[s[j]]++;
		//2.condition map.size
		if (mp.size() < k)
			j++;
		else if (mp.size() == k)
		{
			window_size = max(window_size , j - i + 1);
			j++;
		}
		else if (mp.size() > k)
		{
			while (mp.size() > k)
			{
				mp[s[i]]--;
				if (mp[s[i]] == 0)
					mp.erase(s[i]);
				i++;
			}
			j++;
		}
	}
	return window_size;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k;
	string s;
	cin >> s >> k;
	cout << longestKSubstr(s, k);



	return 0;
}