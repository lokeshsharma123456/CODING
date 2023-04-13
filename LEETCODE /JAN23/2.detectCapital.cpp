#include<bits/stdc++.h>
using namespace std;

#define ll long long int


bool detectCapitalUse(string word)
{
	int n = word.size();
	if (n == 1)
		return true;

	char ch = word[0];
	if (ch >= 'a' && ch <= 'z')
	{
		int i = 1;
		while (i < n)
		{
			if (word[i] < 'a' || word[i] > 'z')
				return false;
			i++;

		}
	}
	else //capital is first
	{
		ch = word[1];
		if (ch >= 'a' && ch <= 'z')
		{
			int i = 1;
			while (i < n)
			{
				if (word[i] < 'a' || word[i] > 'z')
					return false;
				i++;
			}
		}
		else //2nd bhi capital
		{
			int i = 1;
			while (i < n)
			{
				if (word[i] >= 'a' && word[i] <= 'z')
					return false;
				i++;

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

	int t;
	cin >> t;
	while (t--)
	{

		string word;
		cin >> word;
		// cout << word;
		cout << detectCapitalUse(word) << endl;
	}



	return 0;
}

