#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
	if (n <= 1) {
		return n;
	}


	if (n <= 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
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
		cout << fibo(n) << endl;

	}





	return 0;
}