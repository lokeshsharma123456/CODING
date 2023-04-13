#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class DLLNode
{
public:
	int data;
	DLLNode *next;
	DLLNode *prev;
};

int ans = 0;
void helper(DLLNode* head, int x, int tp, int sum)
{
	// cout  << sum << " " << tp << "\n";

	if (x == sum && tp == 3)
	{
		ans++;
		return ;
	}
	if (!head || tp  > 3 || sum > x)
		return ;

	// cout << head->data << " " << sum << " " << tp << "\n";
	helper(head->next, x, tp, sum);
	helper(head->next, x, tp + 1, sum + head->data);
}

int countTriplets(DLLNode* head, int x)
{
	int tp = 0;
	int sum = 0;
	helper(head, x, tp , sum);
	return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	DLLNode *head = NULL;
	DLLNode*tail = NULL;
	int flag = 1;
	while (1) {
		int k;
		cin >> k;
		if (k == -1)
			break;
		DLLNode*node = new DLLNode();
		node->data = k;
		if (flag)
		{
			tail = node;
			head = node;
			flag = 0;
		}
		else
		{

			tail->next = node;
			tail = node;
		}
	}

	tail = head;
	while (tail)	{
		cout << tail->data << " ";
		tail = tail->next;
	}
	cout << endl;
	int x;
	cin >> x;
	cout << countTriplets(head, x);


	return 0;
}