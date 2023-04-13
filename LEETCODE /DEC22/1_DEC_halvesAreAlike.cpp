/*
You are given a string s of even length.
Split this string into two halves of equal lengths,
 and let a be the first half and b be the second half.

Two strings are alike if they have the same number
of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
 Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
Therefore, they are not alike.
Notice that the vowel o is counted twice.


Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool check_vowel(char c)
{
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' )
		return true;
	else
		return false;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	string s;
	cin >> s;
	while (t--)
	{
		int first_half = 0 , second_half = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (i < s.length() / 2)
			{
				if (check_vowel(s[i]))
					first_half++;
			}
			else {
				if (check_vowel(s[i]))
					second_half++;
			}
		}
		if (first_half == second_half)
			cout << "true\n";
		else
			cout << "false\n";
	}



	return 0;
}