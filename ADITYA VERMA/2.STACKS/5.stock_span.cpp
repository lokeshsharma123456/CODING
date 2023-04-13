/*
The stock span problem is a financial problem where we have a
 series of n daily price quotes for a stock and we need to calculate
 the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the maximum
number of consecutive days just before the given day,
for which the price of the stock on the current day is
less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as
{100, 80, 60, 70, 60, 75, 85}, then the span values for
corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input:
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector <int> calculateSpan(int price[], int n)
{
	stack<int>st;
	vector<int>v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		if (st.empty() || price[i] < price[st.top()])
		{
			v[i] = 1;
			st.push(i);
		}
		else if (price[i] >= price[st.top()])
		{
			int cnt = 1;
			while (!st.empty() && price[i] >= price[st.top()])
			{
				cnt += v[st.top()];
				st.pop();
			}
			if (st.empty() || price[i] < price[st.top()])
			{
				v[i] = cnt;
				st.push(i);
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
	int n;
	cin >> n;
	int price[n];
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	vector<int >v = calculateSpan(price, n) ;
	for (auto val : v)
		cout << val << " ";


	return 0;
}