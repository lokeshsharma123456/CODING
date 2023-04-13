#include<bits/stdc++.h>
using namespace std;
string sub(string str1, string str2)
{
	int l1 = str1.length() - 1;
	int l2 = str2.length() - 1;
	if (l1 < l2)
	{
		//swapping string
		string temp = "";
		temp = str2;
		str2 = str1;
		str1 = temp;
		//swapping length;
		int x = l2;
		l2 = l1;
		l1 = x;
	}

	int n1 = l1 ;
	int n2 = l2;

	int borrow = 0;
	string str = "";

	int dif;





	char c;
	while ( n2 >= 0)
	{

		dif = (str1[n1] - '0')  - (str2[n2] - '0') - borrow;
		if (dif < 0)
		{
			borrow = 1;
			c  = (dif  + 10) + 48;
		}
		else
		{
			borrow = 0;
			c = (dif + 48);
		}

		n1 --;
		str =  c + str;
		n2 --;


	}



	while (n1 >= 0)
	{

		dif = (str1[n1] - 48)   - borrow;
		if (dif < 0)
		{
			borrow = 1;
			c  = (dif  + 10) + 48;
			// cout << "dif  is : " << dif << endl;
			// cout << c << endl;
		} else
		{
			borrow = 0;
			c = (dif + 48);
		}





		str =  c + str;

		n1 --;


		//cout << "string till now :" << str << endl;
	}


	int cn  = 0;
	int i = 0;
	string result = str;

	while (str[i] == 48)
	{
		cn++;

		i++;
	}

	if (cn == str.length())
	{
		str = "0";
	}
	else {

		str = str.substr(cn);


	}



	return str;



}

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


string factorial(string str1)
{
	string one = "1";
	string str = str1;
	string zero = "0";
	if (str1 == "0" || str1 == "1")
		return one;

	string prod = str1;
	while (str1 != one)
	{
		string one_less = sub(str1 , one);


		prod = mul (prod, one_less);
		str1 = one_less;
	}
	return prod;

}

string gcd(string str1 , string str2)
{
	string zero = "0";
	if (str1 == zero)
		return str2;
	if (str2 == zero)
		return str1;
	if (str1 == str2)
		return str1;
	string dif = sub()

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
	string s3 = gcd(s1, s2);
	cout << s3;
	return 0;
}
