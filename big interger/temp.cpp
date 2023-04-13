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
	while ( n2 >= 0)
	{
		if ((str1[n1] - 48) < (str2[n2] - 48))
		{
			dif = (str1[n1] - 48) + 10 - (str2[n2] - 48) - borrow;
			borrow = 1;
		}
		else
		{
			dif =  (str1[n1] - 48) - (str2[n2] - 48) - borrow ;
			borrow = 0;
		}

		char c  = dif + 48;
		str =  c + str;

		n1 --;
		n2 --;
	}
	while (n1 >= 0)
	{
		dif =  (str1[n1] - 48)  - borrow ;
		borrow = 0;
		char c  = dif + 48;
		str =  c + str;
		n1 --;
	}
	return str;
}
string ssss(string ss)
{
	ss = "0";
	return ss;
}
int main()
{
#ifdef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "r", stdin);
#endif

	string se = "1";
	string s = "5";
	int p = 0;
	while (s != "0" && p < 12)
	{
		cout << s << endl;
		s = sub(s , se);
		p++;

	}
	char c = (-9 + 10)  + 48;
	cout << c;


	return 0;
}


/*
https://mkp.gem.gov.in/quilted-cloth/og-quilted-cloth/p-5116877-40060439384-cat.html



https://mkp.gem.gov.in/quilted-cloth/setti-cover-cloth-table-cover-cloth/p-5116877-14610566172-cat.html




*/