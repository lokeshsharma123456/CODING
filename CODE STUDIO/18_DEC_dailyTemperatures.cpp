#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int st = 0;
vector<int> dailyTemperatures(vector<int>& temperatures)
{
	vector <int>v;
	int arr[101] = {0};
	for (int i = 0; i <= 100; i++)
		arr[i] = 0;

	int n = temperatures.size();

	for (auto val : temperatures)
		arr[val]++;

	for (int i = 0; i < n - 1; ++i)
	{
		int j;
		int cur_temp = temperatures[i];
		int val = 0;
		int check = 0;
		arr[temperatures[i]]--;
		for (int k = temperatures[i] + 1; k < 101; k++)
		{
			if (arr[k])
			{
				check = 1;
				break;
			}
		}
		if (check)
		{
			for (j = i + 1; j < n; j++)
			{
				val++;
				st++;
				if (cur_temp < temperatures[j])
					break;
			}
			v.push_back(val);
		}
		else
			v.push_back(0);
	}
	v.push_back(0);
	return v;
}
void print(vector<int>v)
{
	for (auto val : v)
		cout << val << " ";
	cout << std::endl;
}
vector<int> dailyTemperatures1(vector<int>& temperatures)
{
	vector<int>v;
	stack<int>st; //value,index
	int n = temperatures.size() - 1;
	// cout << "hi\n";
	for (int i = n; i >= 0; i--)
	{
		// print(v);
		if (st.size() == 0)
		{
			v.push_back(0);
			st.push(i);
		}
		else
		{
			if (temperatures[i] < temperatures[st.top()] )
			{
				v.push_back(st.top() - i);
				st.push(i);
			}
			else
			{
				while (st.size() != 0 && temperatures[i] >= temperatures[st.top()]  )
				{
					st.pop();
				}
				if (st.size() == 0)
				{
					v.push_back(0);
					st.push(i);
				}
				else
				{
					v.push_back(st.top() - i);
					st.push(i);
				}
			}
		}
	}
	reverse(v.begin(), v.end());
	return v;

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
		int  n;
		cin >> n;
		vector<int>temp;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			temp.push_back(k);
		}
		// vector <int>v = dailyTemperatures(temp);
		vector <int>v = dailyTemperatures1(temp);
		for (auto x : v)
			cout << x << " ";
		cout << endl;
	}


	return 0;
}