/*
There is a carpet of a size a*b [length * breadth].
You are given a box of size c*d. The task is,
one has to fit the carpet in the box in a minimum number of moves.

In one move, you can either decrease the length or
the breadth of the carpet by half (floor value of its half).

Note: One can even turn the carpet by 90 degrees any
number of times, wont be counted as a move.


*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int getfolds(int &b_max , int &d_max)
{
	int fold = 0;
	while (b_max > d_max) {
		fold ++;
		b_max = b_max / 2;
		cout << b_max << " " << d_max << " " << fold << endl;
	}
	return fold;
}
void swapping(int &a, int &b)
{
	if (a < b)
		return;
	else
	{
		int temp = a;
		a = b;
		b = temp;
	}
}
int carpetBox(int a_min, int b_max, int c_min, int d_max)
{
	swapping(a_min, b_max);
	swapping(c_min, d_max);
	int fold = 0;
	if (a_min <= c_min)
	{
		fold += getfolds(b_max, d_max);
	}
	else if (a_min > c_min) //8>6
	{
		if (a_min <= d_max) //8<10
		{
			if (b_max > d_max) //13>10 or 14>10
			{
				if (b_max / 2 <= c_min) //13/2 = 6 <= 6 ok
				{
					b_max = b_max / 2;
					swapping(a_min, b_max);
					fold++;
				}
				else //14/2 = 7 , 6<7<8 why to do extra fold go with a_min
				{
					fold += getfolds(a_min , c_min);
					fold += getfolds(b_max , d_max);
				}
			}
			else
			{
				fold += getfolds(a_min , c_min);
			}
		}
		else
		{
			fold += getfolds(a_min , c_min);
			fold += getfolds(b_max , d_max);
		}
	}

	return fold;
}

int helper(int a, int b, int t)
{
	// cout << a << " " << b << " " << t << endl;
	if (a <= b)
		return 0;
	else
		return 1 + helper(a / 2, b , t + 1);
}

int carpetBox1(int a, int b, int c, int d)
{
	// int t = 0;
	return min(helper(a, c, 0) + helper(b, d, 0) , helper(a, d, 0) + helper(b, c, 0));
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << carpetBox(a, b, c, d) << endl << "\n\n\n";
	cout << carpetBox1(a, b, c, d) << endl;


	return 0;
}