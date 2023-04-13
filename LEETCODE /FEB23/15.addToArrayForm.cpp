#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> addToArrayForm(vector<int>& num, int k)
{
	reverse(num.begin(), num.end());

	stack<int>st;
	std::vector<int> ans;
	int sum = k;
	while (sum > 0)
	{
		st.push(sum % 10);
		sum /= 10;
	}

	vector<int>v;
	while (st.size())
	{
		v.push_back(st.top());
		st.pop();
	}
	reverse(v.begin(), v.end());
	int carry = 0;
	int i = 0;
	while (i < min(num.size(), v.size()))
	{
		sum = num[i] + v[i] + carry;
		ans.push_back(sum % 10);
		carry = sum / 10;
		i++;
	}

	if (num.size() > v.size())
	{
		while ( i < num.size())
		{
			sum = num[i] + carry;
			ans.push_back(sum % 10);
			carry = sum / 10;
			i++;
		}
	}
	else
	{
		while ( i < v.size())
		{
			sum = v[i] + carry;
			ans.push_back(sum % 10);
			carry = sum / 10;
			i++;
		}
	}


	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> num;
	while (1) {
		int a;
		cin >> a;
		if (a == -1)
			break;
		num.push_back(a);
	}
	int k;
	cin >> k;
	vector<int> v = addToArrayForm(num,  k) ;
	for (auto val : v)
		cout << val << " ";

	return 0;
}