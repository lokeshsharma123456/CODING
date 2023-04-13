#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
	stack<long long>st;
	vector<long long> v(n, 0) ;
	for (int i = n - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			v[i] = -1;
			st.push(arr[i]);
		}
		else if (arr[i] < st.top())
		{
			// cout << arr[i] << endl;
			v[i] = st.top();
			st.push(arr[i]);
		}
		else if (arr[i] >= st.top())
		{
			while (st.size() && arr[i] >= st.top())
			{
				st.pop();
			}
			if (st.empty())
			{
				v[i] = -1;
				st.push(arr[i]);
			}
			else if (arr[i] < st.top())
			{
				v[i] = st.top();
				st.push(arr[i]);
			}

		}
	}
	return v;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<long long> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long k;
		cin >> k;
		arr.push_back(k);
	}
	vector<long long> v = nextLargerElement(arr, n);
	for (auto val : v)
		cout << val << " ";


	return 0;
}