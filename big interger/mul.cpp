#include<bits/stdc++.h>
using namespace std;

string mul(string str1, string str2)
{
	int l1 = str1.length() ;
	int l2 = str2.length();
	int len = l1 + l2;

	int *result = new int[len] {0};


	if (l1 < l2)
	{
		//swapping string
		string temp = "";
		temp = str2;
		str2 = str1;
		str1 = temp;
		//swapping length;
		int t = l2;
		l2 = l1;
		l1 = t;
	}

	int x = 0; //power factor shift left
	int n1 = l1 - 1 ;
	int n2 = l2 - 1;


	string str = "";
	int index2 = n2;


	for (int index2 = n2; index2 >= 0; --index2 )
	{
		int carry = 0 ;
		for (int index1 = n1; index1 >= 0 ; --index1)
		{
			int product  = (str2[index2] - 48) * (str1[index1] - 48) ;
			int sum = product + result[index2 + index1 + 1];
			//result ka index always more than 1
			result[index2 + index1 + 1] = sum % 10;
			carry = sum / 10;
			result[index2 + index1] += carry;

		}

	}

	int c  = 0;
	int i = 0;
	while (result[i++] == 0)
	{
		c ++;
	}
	for (int i = c ; i < len; i++)
	{
		char c = (result[i] + 48);
		str = str + c;

	}
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
	string s3 = mul(s1, s2);
	cout << s3;
	return 0;
}










/*
PAINT BRUSH 100MM
https://mkp.gem.gov.in/paint-brushes/unbranded-paint-brush/p-5116877-78242962767-cat.html#variant_id=5116877-78242962767

*/