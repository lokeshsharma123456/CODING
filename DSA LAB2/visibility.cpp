#include<bits/stdc++.h>
using namespace std;


int main()
{
#ifdef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];

		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << arr[i] << " ";

		// }



		for (int i = 0; i < n; ++i)
		{
			int j = i - 1;
			int currmax = arr[i];
			while (j > -1)
			{
				if (arr[j] > arr[i])
				{
					cout << arr[j] << " ";
					j = -3;
				}
				else
					j--;
			}
			if (j == -1)
				cout << j << " ";

		}
		cout << endl;
	}




	return 0;
}