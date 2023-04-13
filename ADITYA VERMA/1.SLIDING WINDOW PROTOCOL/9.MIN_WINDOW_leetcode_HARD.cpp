#include<bits/stdc++.h>
using namespace std;

#define ll long long int
string minWindow(string s, string t)
{
	unordered_map<char, int>mp;
	if (s.size() < t.size())
		return "";
	int i = 0, j = 0;
	int beg, end;
	int win_size = INT_MAX;
	//STARTING ME COMPARE KARNE K LIYE

	while (i < t.size())
	{
		mp[t[i]]++;
		i++;
	}
	i = 0;

	int counter = mp.size();
	while (j < s.size())
	{
		if (mp.find(s[j]) == mp.end()) //not in mp so skip
			j++;
		else //if in map
		{
			mp[s[j]]--;
			// cout << s[j] << " " << mp[s[j]] << endl;
			if (mp[s[j]] == 0) //check counter
				counter --;
			//if counter is zero now the window has the answer so optimize the window
			if (counter == 0)
			{
				while (counter == 0)
				{
					if (win_size > j - i + 1)
					{
						win_size = j - i + 1;
						beg = i;
						end = j;
					}
					if (mp.find(s[i]) ==  mp.end()) //not found
						i++;
					else//if found
					{
						// cout << "win_size: " << win_size << endl;
						// cout << "countr ==0: " << i << " " << j << endl;
						mp[s[i]]++;
						if (mp[s[i]] > 0)
							counter ++;
						i++;
					}
				}
			}

			j++;
		}
	}
	string str = "";
	// cout << i << " " << j << endl;
	for (int k = beg; k < end + 1 ; k++)
		str += s[k];

	return str;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int test;
	cin >> test;
	while (test --)
	{
		string s , t;
		cin >> s >> t;
		cout << s.length() << endl;
		string x = minWindow(s, t);
		// cout << x << endl;
	}


	return 0;
}