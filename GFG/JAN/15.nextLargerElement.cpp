#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
	stack<long long>st;
	// int n = arr.size();
	vector<long long>v(n , 0);
	int i = n - 1;
	while (i >= 0)
	{
		if (st.size() == 0)
		{
			v[i] = -1;
			st.push(arr[i]);
			i--;
		}
		else//stack me kuch hai
		{
			if (arr[i] < st.top())//top bda hai to direct mil gya
			{
				v[i] = st.top();
				st.push(arr[i]);
				i--;
			}
			else // varna jb tk top bda na mile ya st khalin na ho jaye pop
			{
				while (st.size() && arr[i] > st.top())
					st.pop();
				if (st.size())
				{
					v[i] = st.top();
					st.push(arr[i]);
				}
				else
				{
					v[i] = -1;
					st.push(arr[i]);
				}
				i--;
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
		int k;
		cin >> k;
		arr.push_back(k);
	}

	vector<long long>v = nextLargerElement(arr, n);
	for (auto val : v)
		cout << val << " ";


	return 0;
}