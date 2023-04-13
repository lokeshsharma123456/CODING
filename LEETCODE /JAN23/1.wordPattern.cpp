#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool wordPattern(string pattern, string s)
{
	unordered_map<char, int>mp_pattern;
	unordered_map<string, int>mp_s;
	string cnt_pat = "";
	string cnt_s = "";
	int val = 1;
	int i = 0;
	while (i < pattern.size())
	{
		if (mp_pattern.find(pattern[i]) != mp_pattern.end())
			cnt_pat +=  to_string(mp_pattern[pattern[i]]) ;
		else
		{
			mp_pattern[pattern[i]] = val;
			cnt_pat +=  to_string(mp_pattern[pattern[i]]) ;
			val++;
		}
		i++;
	}
	// cout << cnt_pat << endl;

	i = 0;
	val = 1;
	// s += "$";
	while (i < s.size())
	{
		string k = "";
		while (s[i] != ' ' && s[i] != '\0')
			k += s[i++];
		if (mp_s.find(k) != mp_s.end())
			cnt_s +=  to_string(mp_s[k]) ;
		else
		{
			mp_s[k] = val;
			cnt_s +=  to_string(mp_s[k]) ;
			val++;
		}
		i++;
	}
	// cout << cnt_s << endl;
	if (cnt_s == cnt_pat)
		return 1;


	return 0;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string pattern , s;
	cin >> pattern;
	cin.get();
	getline(cin, s);
	cout << s << endl;
	cout << wordPattern(pattern, s) << endl;



	return 0;
}