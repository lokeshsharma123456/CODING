#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void print(vector<int>v)
{
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}
void print( deque<int>q)
{
	while (!q.empty()) {

		// getting front element of queue
		cout << q.front() << " ";

		// removing front element of queue
		q.pop_front();
	}
	cout << endl;
}

vector<int> slidingMaximum(const vector<int> &a, int k)
{
	deque<int>q;
	int beg = 0, end = 0;
	int n = a.size();
	vector<int> v;

	while (end < n)
	{
		//calculation
		if (q.empty())
			q.push_back(a[end]);
		else if (q.back() > a[end])
			q.push_back(a[end]);
		else
		{
			while (!q.empty() && q.back() < a[end])
				q.pop_back()  ;
			q.push_back(a[end]);
		}

		//check
		if (end - beg + 1 < k)
			end++;
		else if (end - beg + 1 == k)
		{
			if (a[beg] == q.front())
			{
				v.push_back(q.front());
				q.pop_front();
			}
			else
				v.push_back(q.front());
			beg++;
			end++;
			// print(v);
		}
		print(q);
	}
	return v;
} 0

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
		int n;
		cin >> n;
		vector<int>a(n, 0);

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		int k;
		cin >> k;
		vector<int> v;

		v = slidingMaximum(a, k);
		for (auto val : v)
		{
			cout << val << " ";
		}
		cout << endl;

	}




	return 0;
}