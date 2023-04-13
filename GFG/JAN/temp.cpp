#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int leng(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}
int fun(int n, int flag)
{
	if (n <= 0)
		return 0;
	flag = flag * -1;
	return (n % 10) * flag + fun(n / 10, flag );
}
int alternateDigitSum(int n)
{
	int len = leng(n);
	if (len % 2 == 1)
		return fun(n, -1);
	return fun(n, 1);//when even
}

vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k)
{
	vector < vector<int>>v;
	for (int i = 0; i < score.size(); ++i)
	{
		vector<int>ki;
		ki.push_back(score[i][k]);
		ki.push_back(i);
		v.push_back(ki);
	}
	sort(v.begin(), v.end());

	vector < vector<int>>final;
	for (int i = v.size() - 1; i >= 0 ; --i)
	{
		final.push_back(score[v[i][1]]);
	}
	return final;
}

bool makeStringsEqual(string s, string target)
{
	int s0 = 0, s1 = 0;
	if (s.length() != target.length())
		return false;
	if (s == target)
		return true;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '0')
			s0++;
		else
			s1++;
	}
	int t0 = 0, t1 = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (target[i] == '0')
			t0++;
		else
			t1++;
	}

	if (s0 == s.length() && t1 > 0)
		return false;

	if (s1 == s.length() && t0 > 0)
		return false;

	if (t0 == s.length() && s1 > 0)
		return false;

	if (t1 == s.length() && s0 > 0)
		return false;
	return true;


}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s, t;
	cin >> s >> t;
	cout << makeStringsEqual(s, t) << endl;


	return 0;
}

