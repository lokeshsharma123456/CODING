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
	string s3 = sub(s1, s2);
	cout << s3;


	return 0;
}

