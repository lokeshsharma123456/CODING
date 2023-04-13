#include<bits/stdc++.h>
using namespace std;
//#include "arithematic.h"
string sum(string str1, string str2)
{
	int l1 = str1.length() - 1;
	int l2 = str2.length() - 1;
	int n1 = l1 ;
	int n2 = l2;

	int carry = 0;
	string str = "";

	int sum;



	// cout << str1[3] << endl;
	// cout << str2[0] << endl;


	while (n1 >= 0 && n2 >= 0)
	{

		sum =  (str1[n1] - 48) + (str2[n2] - 48) + carry;
		cout << "sum of " << str1[n1] << " " << str2[n2] << " is : " << sum << endl;
		carry = sum / 10;
		char c  = sum % 10 + 48;
		str =  c + str;

		n1 --;
		n2 --;

		cout << "string till now :" << str << endl;

	}

	//check whose length greater
	int len ;
	string temp = "";
	if (l1 > l2)
	{
		len = n1;
		temp = temp + str1;
	}
	else
	{
		len = n2;
		temp = temp + str2;
	}


	while (len >= 0)
	{
		sum = temp[len] - 48 + carry;
		carry = sum / 10;
		char c  = sum % 10 + 48;
		str =  c + str;
		len--;

	}

	if (carry > 0)
	{
		string s;
		s = (carry + 48);
		str = s + str;
		return str;
	}
	else
		return str;



}


int main()
{
#ifdef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "r", stdin);
#endif


	string s1 ;
	string s2 ;
	cin >> s1;
	cin >> s2;
	string s3 = sum(s1, s2);
	cout << s3;


	return 0;
}
/*

http://www.cs.fsu.edu/~lacher/courses/COP5517/lectures/deques/script.html

*/