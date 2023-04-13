#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<vector<string>>v;
bool ispalindrome(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

void helper(string s, vector<string>&temp)
{
	if (!s.size())
	{
		v.push_back(temp);
		return;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		string prefix = s.substr(0, i + 1);
		// string ros = s.substr(i+1);
		if (ispalindrome(prefix))
		{
			temp.push_back(prefix);
			helper(s.substr(i + 1), temp);
			temp.pop_back();
		}
	}
}
vector<vector<string>> partition(string s)
{
	vector<string>temp;
	helper(s, temp);
	return v;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	vector<vector<string>> v = partition(s);
	for (int i = 0; i < v.size(); ++i)
	{
		for (auto val : v[i])
			cout << val << " ";
		cout << endl;
	}

	return 0;
}