#include<bits/stdc++.h>
using namespace std;


int wormhole(int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	int a = wormhole(n - 2);
	int b = wormhole(n - 3);
	int c = wormhole(n - 5);


	int count[dist + 1];

	// Initialize base values. There is one way to cover 0 and 1
	// distances and two ways to cover 2 distance
	count[0] = 2;
	if (dist >= 1)
		count[1] = 3;
	if (dist >= 2)
		count[2] = 5;

	// Fill the count array in bottom up manner
	for (int i = 3; i <= dist; i++)
		count[i] = count[i - 1] + count[i - 2] + count[i - 3];

	return count[dist];
	return a + b + c;
}

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
		int n;
		cin >> n;

		cout << wormhole(n) << endl;

	}
	return 0;
}