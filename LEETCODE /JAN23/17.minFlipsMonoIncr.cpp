#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int minFlipsMonoIncr(string s)
{
	int ans = 0;
	int one = 0;
	int n = s.length();
	int i = 0;
	while (i < n)
	{
		if (s[i] == '1')
			one++;
		else
		{
			//zero pe dekho agar
			ans = min(ans + 1/*0 ko 1 bna do */ , one/*1 ko 0 bna do*/ );
		}
		i++;
	}
	return ans;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	cout << minFlipsMonoIncr(s);


	return 0;
}