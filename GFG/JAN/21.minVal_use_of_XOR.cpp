#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int setBits(int x)
{
	if (x == 0)
		return 0;
	else
		return (x & 1) + setBits(x >> 1);

}
int minVal(int a, int b)
{
	int set_bits_B = setBits(b);
	int set_bits_A = setBits(a);

	return 0;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a , b;
	cin >> a >> b;
	cout << minVal(a, b) << endl;

	// cout << setBits(b);



	return 0;
}