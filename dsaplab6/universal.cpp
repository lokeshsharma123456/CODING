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

		int n, k,  mindays = 99999;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < n; ++i)
		{
			if (arr[i] <= 0)
				continue;
			int sum = 0;
			int count = 0;
			sum = arr[i];
			if (sum >= k)
			{
				cout << "1" << endl;
				break;
			}

			for (int j = i + 1 ; j < n; j++)
			{

				sum  += arr[j];

				count++;
				if (sum >= k)
				{
					break;
				}
			}
			mindays = min(mindays, count);
		}
		cout << mindays << endl;


	}



	return 0;
}
// Example 1:

// Input:
// 90 100 -> N = 10, K=100
// 30 40 50 20 20 10 90 10 10 10 -> Price to make bet on each horse in order
// Output:
// 3
// Explanation:
// There are 10 horses, and the reward money is 100.
// So, Bob will put money in less than 100.
// There are two possible o sequences of length three whose total money for betting is less than 100, i.e. [50 20 20] (sum is 90) and [10 10 10] (sum is 30). Bob will choose randomly one sequence from these two. As none of the other sequences with a length greater than 3 will have a price less than 100 so the answer will be 3.
// Example 2:

// Input:
// 10 100 -> N = 10, K=100
// 10 90 80 20 90 60 40 60 70 75 -> Price to make bet on each horse in order
// Output:
// 1
// Explanation:
// There are no two consecutive horses for which the sum of price is less than 100.
// So, Bob will choose randomly any one horse. And the max length of the sequence will be 1.











// int n;
// 	cin >> n;
// 	// int *arr = new int[n];
// 	std::vector<int> v;
// 	int i = 0;
// 	while (i < n)
// 	{






// int a;
// 	cin >> a ;
// 	v.push_back(a);
// 	sort(v.begin(), v.end());
// 	// for (auto i = v.begin(); i < v.end(); i++)
// 	// {
// 	// 	cout <<  *i << " ";
// 	// }
// 	// cout << endl;
// 	if (i == 0)
// 		cout << v[0] << " ";
// 	else if (i == 1)
// 		cout << (v[0] + v[1]) / 2 << " ";
// 	else if ((i + 1) % 2 == 1) //odd 3  5 7
// 		cout << (v[i / 2]) << " " ;
// 	else if ((i + 1) % 2 == 0)
// 		cout << (v[(v.size() - 1) / 2] + v[((v.size() - 1) / 2) + 1] ) / 2 << " ";
// 	i++;
// 	// cout << endl;
// }