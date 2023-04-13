/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int lengthOfLongestSubstring(string s)
{
	int i = 0, j = 0;
	unordered_map<char, int>mp;
	int window_size = 0;
	int n = s.size();
	while (j < n )
	{
		//1.calclation
		mp[s[j]]++;
		//2. cond if(mps[j] >1)
		if (mp[s[j]] == 1)
		{
			int k = mp.size();
			// window_size = max( window_size,  mp.size());
			// cout << mp.size() << endl;
			window_size = max(window_size, k);
			j++;
		}
		else if (mp[s[j]] > 1)
		{
			while (mp[s[j]] > 1)
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
	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;


	return 0;
}