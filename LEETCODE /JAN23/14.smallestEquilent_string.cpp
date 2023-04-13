#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void change(char a, char b, unordered_map<char, int>&mp)
{
	int bade_ka_index = mp[b];
	//jis jis ka index similar to b hai use chote se replace karo
	int chote_ka_index = mp[a];
	for (auto val : mp)
	{
		if (val.second == bade_ka_index)
		{
			mp[val.first] = chote_ka_index;
		}
	}
}
string smallestEquivalentString(string s1, string s2, string baseStr)
{
	unordered_map<char, int>mp;
	std::vector<std::vector<char>> v(26);

	int index = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		char a = s1[i];
		char b = s2[i];
		if (mp.find(a) == mp.end() && mp.find(b) == mp.end())
		{
			mp[a] = index;
			mp[b] = index;
			index++;

		}
		else if (mp.find(a) != mp.end() && mp.find(b) == mp.end() )
		{
			int ind = mp[a];
			mp[b] = ind;
		}
		else if (mp.find(a) == mp.end() && mp.find(b) != mp.end() )
		{
			int ind = mp[b];
			mp[a] = ind;
		}
		else if (mp.find(a) != mp.end() && mp.find(b) != mp.end() )
		{
			if (a < b)
				change(a, b, mp);
			else
				change(b, a, mp);
		}
	}
	for (auto val : mp)
	{
		v[val.second].push_back(val.first);
	}

	for (int i = 0; i < index; ++i)
	{
		sort(v[i].begin(), v[i].end());
	}


	string str = "";
	for (int i = 0; i < baseStr.size(); ++i)
	{
		int a = baseStr[i];
		int ind;
		if (mp.find(a) != mp.end()) //mil gya to
		{
			ind = mp[a];
			str += v[ind][0];
		}
		else
			str += a;
	}
	return str;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t ;
	cin >> t;
	while (t--) {
		/* code */
		string s1;
		string s2 , baseStr;
		cin >> s1 >> s2 >> baseStr;
		// std::cout << s1 << s2 << baseStr;
		cout << smallestEquivalentString(s1, s2, baseStr) << endl;
	}


	return 0;
}