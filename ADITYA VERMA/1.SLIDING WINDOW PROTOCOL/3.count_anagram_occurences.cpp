#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void print(vector<int>v)
{
	for (int x = 0; x < 26; ++x)
	{

		if (v[x] > 1)
		{
			int k = v[x];
			cout << (char)(x + 'a') << v[x] << " ";
		}
		else if (v[x] == 1)
		{
			cout << (char)(x + 'a') << v[x] << " ";
		}

	}
	cout << endl;
}

int search(string pat, string txt)
{
	vector<int>v(26, 0), d(26, 0);
	int count = 0;
	int len = pat.length();
	int n = txt.length();
	for (int i = 0; i < len; ++i)
		v[pat[i] - 'a']++;

	// print(v);

	for (int i = 0; i < len; ++i)
		d[txt[i] - 'a']++;

	// print(d);
	if (d == v)
		count++;
	int end = len, beg = 0;

	while (end < n)
	{
		d[txt[beg] - 'a']--;
		d[txt[end] - 'a']++;
		// print(d);
		if (d == v)
			count++;
		beg++;
		end++;
	}
	return count;
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
		string pat, txt;
		cin >> pat >> txt;
		cout << search(pat, txt) << endl;
	}
	return 0;
}