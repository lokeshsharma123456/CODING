#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void print(int *a)
{
	for (int i = 0; i < 26; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
bool closestrings(string a, string b)
{
	// for (int i = 0; i < 26; ++i)
	// 	cout << i % 10 << " ";
	// cout << std::endl;
	// for (int i = 0; i < 26; ++i)
	// {
	// 	cout << (char)(97 + i) << " ";
	// }
	if (a.length() != b.length())
		return 0;
	int* a_len = new int[26] ;
	int * b_len = new int [26];
	for (int i = 0; i < 26; ++i)
	{
		a_len[i] = 0;
		b_len[i] = 0;
	}
	int t = a.length();
	for (int i = 0; i < t; ++i)
	{
		int index = a[i] - 'a';
		a_len[index]++;
		index = b[i] - 'a';
		b_len[index]++;
	}
	// print(a_len);
	// print(b_len);
	for (int j = 0; j < 26; ++j)
	{
		if ((a_len[j] && !b_len[j]) || (!a_len[j] && b_len[j]) )
		{
			// cout << a_len[j] << " " << b_len[j] << endl;
			// cout << "j:" << j << endl;
			return 0;
		}
	}

	sort(a_len, a_len + 26);
	sort(b_len, b_len + 26);
	// print(a_len);
	// print(b_len);
	for (int i = 0; i < 26; ++i)
	{
		if (a_len[i] != b_len[i] )
			return 0;
	}

	return 1;
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
		string a, b;
		cin >> a >> b;
		cout << closestrings(a, b) << std::endl;
	}


	return 0;
}