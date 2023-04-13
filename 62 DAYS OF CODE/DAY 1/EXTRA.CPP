
#include<bits/stdc++.h>
using namespace std;
int find_fabonacci(int n)
{

	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int smalloutput1 = find_fabonacci(n - 1);
	int smalloutput2 = find_fabonacci(n - 2);


	return smalloutput2 + smalloutput1;




}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	cin >> x ;
	cout << find_fabonacci(x);

	return 0;
}
 