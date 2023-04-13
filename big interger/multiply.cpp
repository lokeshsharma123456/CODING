#include<bits/stdc++.h>
using namespace std;

string mul(string str1, string str2)
{
	int l1 = str1.length() ;
	int l2 = str2.length();
	cout << "len1 " << l1 << " len2  " << l2 << endl;
	int len = l1 + l2;
	cout << len << endl;
	int *result = new int[len] {0};

	// for (int i = 0; i < len; ++i)
	// 	cout << result[i] << " ";
	// cout << endl;

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
			result[index2 + index1 + 1] = sum % 10;
			result[index2 + index1] = result[index2 + index1] + sum / 10;

		}

	}
	// while (index2 >= 0)
	// {
	// 	int num2 = str2[index2] - 48;
	// 	int res_index = (len - 1) - x;
	// 	index2--;


	// 	int carry = 0;
	// 	int index1 = n1;

	// 	while (index1 >= 0 )
	// 	{
	// 		//int num1 = index1 >= 0 ? (str1[n1] - 48) : 0;
	// 		int num1 = (str1[n1] - 48);
	// 		index1--;

	// 		cout << num1 << " " << num2 << " " << num1*num2 << endl;

	// 		result[res_index] = product % 10;

	// 		carry = product % 10;
	// 		res_index--;


	// 	}
	for (int i = 0; i < len; ++i)
		cout << result[i] << " ";
	cout << endl;
	// 	x++;
	// }
	// // for (int i = 0; i < len; ++i)
	// // 	cout << result[i] << " ";
	// // cout << endl;

	int flag = 0;
	int c  = 0;
	int i = 0;
	while (result[i++] == 0)
	{
		c ++;
	}
	cout << c << endl;
	for (int i = c ; i < len; i++)
	{
		char c = (result[i] + 48);
		str = str + c;

	}










// // cout << str1[3] << endl;
// // cout << str2[0] << endl;


// while ( n2 >= 0)
// {
// 	if ((str1[n1] - 48) < (str2[n2] - 48))
// 	{
// 		dif = (str1[n1] - 48) + 10 - (str2[n2] - 48) - borrow;
// 		borrow = 1;
// 	}
// 	else
// 	{
// 		dif =  (str1[n1] - 48) - (str2[n2] - 48) - borrow ;
// 		borrow = 0;
// 	}


// 	cout << "dif of " << str1[n1] << " " << str2[n2] << " is : " << dif << endl;

// 	char c  = dif + 48;
// 	str =  c + str;

// 	n1 --;
// 	n2 --;



// }
// while (n1 >= 0)
// {
// 	dif =  (str1[n1] - 48)  - borrow ;
// 	borrow = 0;
// 	cout << "dif of " << str1[n1]  << " is : " << dif << endl;

// 	char c  = dif + 48;
// 	str =  c + str;

// 	n1 --;


// 	cout << "string till now :" << str << endl;
// }


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