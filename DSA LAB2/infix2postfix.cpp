#include<bits/stdc++.h>
using namespace std;

int priority(char c)
{
	if (c == '+' )
		return 1;
	else if (c == '-' )
		return 2;
	else if (c == '*')
		return 3;
	else if (c == '/')
		return 4;
	else if (c == '^')
		return 5;
	return 0;

}
string Infix2Postfix(string infix)
{
	int len = infix.length();

	string postfix;

	stack<char> Stack;

	for (int i = 0; i < len; i++)
	{

		if (( infix[i] >= 'a'  && infix[i] <= 'z') )
		{

			postfix = postfix + infix[i];

		}

		else if (infix[i] == '(')
		{
			Stack.push('(');
		}




		else if (infix[i] == ')')
		{
			while (Stack.top() != '(')
			{

				postfix = postfix + Stack.top();
				Stack.pop();

			}
			if (Stack.top() == '(')
			{
				char c = Stack.top();
				Stack.pop();
			}
		}






		else {
			while (!Stack.empty() &&  priority(Stack.top() >= priority(infix[i])))
			{

				postfix = postfix + Stack.top();
				Stack.pop();

			}
			Stack.push(infix[i]);
		}
	}

	while (!Stack.empty())
	{

		postfix = postfix + Stack.top();
		Stack.pop();

	}

	return postfix ;
}


int main()
{
#ifdef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "r", stdin);
#endif


	int t;
	cin >> t;
	while (t--)
	{

		string s;
		cin >> s;
		cout << Infix2Postfix(s) << endl;

	}



	return 0;
}