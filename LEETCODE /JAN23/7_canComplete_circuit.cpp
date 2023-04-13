#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int temp = 50;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	vector<int>dif(n, 0);

	int i = 0;
	int prev_sum_to_i = 0;
	while ( i < n)
	{
		if (--temp < 0)
			exit(0);
		dif[i] = gas[i] - cost[i];
		// cout << "prev_sum_to_i :" << prev_sum_to_i << endl;

		if (dif[i] < 0)
		{
			prev_sum_to_i += dif[i];
			i++;
			continue;
		}
		else
		{
			int j = i;
			dif[j] = gas[j] - cost[j];
			// cout << prev_sum_to_i << " " << dif[j] << endl;

			// prev_sum_to_i += dif[i];
			int cur_sum = 0;
			while (j < n && cur_sum >= 0)
			{
				dif[j] = gas[j] - cost[j];
				cur_sum += dif[j];
				// cout << "cur_sum:" << cur_sum << endl;
				if (cur_sum >= 0)
					j++;
				else // cur__sum < 0
				{
					prev_sum_to_i += cur_sum;
					// cout << prev_sum_to_i << endl;
					j++;
					i = j;
					break;
				}
			}
			if (j == n)
			{
				cur_sum += prev_sum_to_i;
				if (cur_sum >= 0)
					return i;
				else
					i++;
			}
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

		int n;
		cin >> n;
		vector<int>gas(n, 0);
		vector<int>cost(n, 0);

		int i = 0;
		while (i < n)
		{
			int k;
			cin >> k;
			gas[i] = k;
			i++;
		}
		i = 0;
		while (i < n)
		{
			int k;
			cin >> k;
			cost[i] = k;
			i++;
		}
		cout << canCompleteCircuit(gas, cost) << endl;
	}

	return 0;
}