#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<string>v;
bool isvalid(string s)
{
	if (s[0] == '0')
		return false;
	if (stoi(s) > 255)
		return false;
	return true;
}



void helper(string s, int index, int par, string ans)
{
	if (index >= s.size() || par >= 4)
	{
		if (index == s.size() &&  par == 4)
		{
			string k = ans.substr(0, ans.length() - 1);
			v.push_back(k);
		}
		return;
	}
	helper(s, index + 1, par + 1, ans + s.substr(index,  1) + ".");


	if ( index < s.length() - 1 && isvalid(s.substr(index, 2)))
		helper(s, index + 2, par + 1, ans + s.substr(index,  2) + ".");

	if (  index  < s.length() - 2 && isvalid(s.substr(index, 3)))
		helper(s, index + 3, par + 1, ans + s.substr(index, 3) + ".");
	return ;

}
vector<string> restoreIpAddresses(string s)
{
	int n = s.length();
	string ans = "";
	helper(s, 0, 0, ans);
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
	vector<string>v = restoreIpAddresses(s);
	for (auto val : v)
		cout << "\nvalid: " << val ;
	// int index = 4;
	// string a = s.substr(index, index + 3);
	// cout << a << endl;
	return 0;
}