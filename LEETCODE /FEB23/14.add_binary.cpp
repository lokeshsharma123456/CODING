#include<bits/stdc++.h>
using namespace std;

#define ll long long int
string addBinary(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.length() < b.length())
		swap(a, b);

	int i = 0;
	string ans = "";
	int carry = 0;
	for (i = 0; i < b.length(); ++i)
	{
		if (carry == 0)
		{
			if (a[i] == '1' && b[i] == '1')
			{
				carry = 1;
				ans += '0';
			}
			else if (a[i] == '1' && b[i] == '0')
			{
				carry = 0;
				ans += '1';
			}
			else if (a[i] == '0' && b[i] == '1')
			{
				carry = 0;
				ans += '1';
			}
			else if (a[i] == '0' && b[i] == '0')
			{
				carry = 0;
				ans += '0';
			}
		}
		else if (carry == 1)
		{
			if (a[i] == '1' && b[i] == '1')
			{
				carry = 1;
				ans += '1';
			}
			else if (a[i] == '1' && b[i] == '0')
			{
				carry = 1;
				ans += '0';
			}
			else if (a[i] == '0' && b[i] == '1')
			{
				carry = 1;
				ans += '0';
			}
			else if (a[i] == '0' && b[i] == '0')
			{
				carry = 0;
				ans += '1';
			}
		}
	}
	while (i < a.length())
	{
		if (carry == 0)
		{
			ans += a.substr(i);
			break;
		}
		else if (carry == 1)
		{
			if (a[i] == '1')
			{
				carry = 1;
				ans += '0';
			}
			else if (a[i] == '0')
			{
				ans += '1';
				carry = 0;
			}
		}
		i++;

	}
	if (carry == 1)
		ans += '1';
	reverse(ans.begin(), ans.end());

	return ans;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	cout << addBinary(a, b);

	return 0;
}