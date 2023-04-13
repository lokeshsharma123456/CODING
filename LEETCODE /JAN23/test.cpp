#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int monkeyMove(int n) {
	long long int sum  = 1;
	for (int i = 1; i <= n; i++)
	{
		sum = (sum * 2) % 1000000007;
		cout << sum << endl;
	}
	return sum - 2;

}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << monkeyMove(n);

	return 0;
}