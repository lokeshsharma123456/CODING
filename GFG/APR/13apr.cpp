#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool validateStackSequences(vector<int>& ps, vector<int>& pp)
{
	int n = ps.size();
	int i = 0, k = 0;
	stack<int>st;
	unordered_map<int, int>mpHit;
	while (k < n)
	{
		if (st.empty())
		{
			st.push(ps[i]);
			mpHit[ps[i]]++;
		}
		else // check map hit
		{
			if (mpHit.find(pp[k]) != mpHit.end()) //if alredy occured
			{
				if (st.top() == pp[k])
				{
					st.pop();
					k++;
				}
				else
					return false;
			}
			else // if not hit
			{
				while (ps[i] != pp[k]) {
					st.push(ps[i]);
					mpHit[ps[i]]++;
					i++;
				}
				if (ps[i] == pp[k])
				{
					k++;
					i++;
				}
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
	vector<int>ps;
	vector<int>pp;
	while (1)
	{
		int k;
		cin >> k;
		if (k == -1)
			break;
		ps.push_back(k);
	}
	while (1)
	{
		int k;
		cin >> k;
		if (k == -1)
			break;
		pp.push_back(k);
	}
	cout << validateStackSequences(ps, pp);

	return 0;
}