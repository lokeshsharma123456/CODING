#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int largestRectangleArea(vector<int>& heights)
{
	int n = heights.size();
	vector<int>NSL(n, 0); //nearest small in left
	vector<int>NSR(n, 0); //nearest small in right

	int psuedoindex = -1;
	stack<int>st;
	for (int i = 0; i < n; ++i)
	{
		if (st.empty())
		{
			NSL[i] = psuedoindex;
			st.push(i);
		}
		else if (heights[i] > heights[st.top()])
		{
			NSL[i] = st.top();
			st.push(i);
		}
		else if (heights[i] <= heights[st.top()])
		{
			while (!st.empty() && heights[i] <= heights[st.top()])
			{
				st.pop();
			}
			if (st.empty())
			{
				NSL[i] = psuedoindex;
				st.push(i);
			}
			else if (heights[i] > heights[st.top()])
			{
				NSL[i] = st.top();
				st.push(i);
			}
		}
	}
	// for (auto val : NSL)
	// 	cout << val << " ";

	psuedoindex = n;
	while (!st.empty())
		st.pop();
	for (int i = n - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			NSR[i] = psuedoindex;
			st.push(i);
		}
		else if (heights[i] > heights[st.top()])
		{
			NSR[i] = st.top();
			st.push(i);
		}
		else if (heights[i] <= heights[st.top()])
		{
			while (!st.empty() && heights[i] <= heights[st.top()])
			{
				st.pop();
			}
			if (st.empty())
			{
				NSR[i] = psuedoindex;
				st.push(i);
			}
			else if (heights[i] > heights[st.top()])
			{
				NSR[i] = st.top();
				st.push(i);
			}
		}
	}
	// cout << endl;
	// for (auto val : NSR)
	// 	cout << val << " ";
	// cout << endl;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		NSR[i] = NSR[i]  - NSL[i] - 1;
		maxi = max(maxi, NSR[i] * heights[i]);
	}

	return maxi;

}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> heights;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long k;
		cin >> k;
		heights.push_back(k);
	}
	cout << largestRectangleArea(heights) << endl;


	return 0;
}