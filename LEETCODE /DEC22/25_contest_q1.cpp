#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int closetTarget(vector<string>& words, string target, int startIndex)
{
	int n = words.size();
	int up = startIndex, down = startIndex;
	if (words[up] == target)
		return 0;
	up = (up - 1) ;
	if (up == -1)
		up = n - 1;
	down = (down + 1) % n;
	int cu = 1, cd = 1;
	while (down != startIndex)
	{
		if (words[up] == target || words[down] == target)
		{
			return cu;
		}
		else
		{
			cu++;
			up = (up - 1) ;
			if (up == -1)
				up = n - 1;
			down = (down + 1) % n;
		}
	}
	return -1;

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
		vector<string>v;
		int n;
		cin >> n;
		while (n--)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}
		string target;
		int startIndex;
		cin >> target >> startIndex;
		cout << closetTarget(v, target, startIndex) << endl;
	}


	return 0;
}