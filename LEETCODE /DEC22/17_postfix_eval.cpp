#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int operators(string s)
{
	// cout << s << endl;
	if (s.size() == 1 && (s == "+" || s == "-" || s ==  "*" || s ==  "/"))
		return 1;
	else
		return 0;
}
int getPrecedence(string s)
{
	char c = s[0];
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 3;

	return 0;
}
ll compute(int a, int b, char c)
{
	if (c == '+')
		return b + a;
	if (c == '-')
		return b - a;
	if (c == '*')
		return b * a;
	if (c == '/')
		return b / a;
	return 0;

}
void doOP(stack<ll>&num, stack<string>&op)
{
	int a = num.top();
	num.pop();
	int b = num.top();
	num.pop();
	string s = op.top();
	char c = s[0];
	op.pop();
	int k = compute(a, b, c);
	// cout << k << endl;
	num.push(k);
}
int evalRPN(vector<string>& tokens)
{
	stack<ll>num;
	stack<string>op;
	op.push("(");
	for (auto val : tokens)
	{
		if (!operators(val))
		{
			num.push(stoi(val));
			// cout << val << endl;
		}
		else
		{
			if (op.size() == 1)
			{
				// cout << val << endl;
				op.push(val);
				doOP(num, op);
				// cout << "num.top  " << num.top() << "  ," << op.top() << endl;
			}
			else
			{
				int top_prior = getPrecedence(op.top());
				int op_prior = getPrecedence(val);
				// cout << op.top() << ", " << top_prior << " ," << val << " " << op_prior << "\n";
				if (top_prior >= op_prior)
				{
					doOP(num, op);
					op.push(val);
				}
				else if (top_prior < op_prior)
					op.push(val);
			}
		}
	}
	while (num.size() != 1)
	{
		doOP(num, op);
	}
	return num.top();
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string>token;
	int t = 10;
	int flag = 1;
	while (flag)
	{
		string k;
		cin >> k;
		if (k == "-1")
			break;
		token.push_back(k);

	}
	int a = 1;
	// for (auto it : token)
	// {
	// 	a *= stoi(it);
	// 	cout << it << " " << a << std::endl;
	// }
	cout << evalRPN(token) << endl;


	return 0;
}