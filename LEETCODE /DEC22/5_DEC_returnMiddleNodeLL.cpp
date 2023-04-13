#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class ListNode
{
public:
	int val;
	ListNode * next;
	ListNode()
	{
		val = 0;
		next = 	NULL;
	}
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};
int lim = 50;
int middle(ListNode * head)
{

	ListNode* doubleJmp = head;
	ListNode* singleJmp = head;

	// cout << singleJmp->val << " ";
	while (doubleJmp && doubleJmp->next)
	{
		singleJmp = singleJmp->next;
		doubleJmp = doubleJmp->next->next;
	}

	// cout << endl;

	return singleJmp->val;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t ;
	cin >> t;
	while (t--)
	{
		ListNode* head = new ListNode();
		ListNode*tail = head;
		int condition = 1;
		int n;
		while (condition)
		{
			if (lim-- <= 0)
				exit(0);
			cin >> n;
			// cout << "hi\n";
			if (n == -1)
			{
				condition = 0;
				break;
			}
			ListNode*newListNode = new ListNode(n);
			tail->next = newListNode;
			tail = tail->next;
		}
		cout << middle(head->next) << endl;
	}





	return 0;
}