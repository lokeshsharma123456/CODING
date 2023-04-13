#include<bits/stdc++.h>
using namespace std;

#define ll long long int
string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
        return "";
    return str1.substr(0, __gcd(str1.length(), str2.length()));
}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str1,  str2;
    cin >> str1 >> str2;
    cout << str1 << " " << str2 << endl;
    cout << gcdOfStrings(str1, str2) << endl;


    return 0;
}