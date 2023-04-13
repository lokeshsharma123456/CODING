#include<bits/stdc++.h>
using namespace std;

#define ll long long int

template <typename T>
class BinaryTreeNode {
public:
	T val;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};


BinaryTreeNode<int>* takeInput() {
	int rootval;
	cin >> rootval;
	if (rootval == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootval);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode<int>* currentNode = q.front();
		q.pop();
		int leftChild, rightChild;

		cin >> leftChild;
		if (leftChild != -1) {
			BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
			currentNode->left = leftNode;
			q.push(leftNode);
		}

		cin >> rightChild;
		if (rightChild != -1) {
			BinaryTreeNode<int>* rightNode =
			    new BinaryTreeNode<int>(rightChild);
			currentNode->right = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}

ll product = 0;
ll M = 1000000000 + 7;

// ll  preorder(BinaryTreeNode<int>*root)
// {
// 	if (!root)
// 		return 0;
// 	// cout << root->val << " ";
// 	return root->val + preorder(root->left) + 	preorder(root->right);
// }
// ll helper(BinaryTreeNode<int>*root ,   ll &sum)
// {
// 	if (!root)
// 		return 0;
// 	ll l = 0 , r = 0;
// 	l = helper(root->left , sum);
// 	ll lnewProd = (l * (sum - l))  ;
// 	r = helper(root->right , sum);
// 	ll rnewProd = (r * (sum - r)) ;
// 	// cout << "root:" << root->val << " ,l:" << l << ",r:" << r ;

// 	product = max(product , max(lnewProd , rnewProd ));

// 	// cout <<  " ,lpd:" << lnewProd << ",rpd:" << rnewProd << endl << "Prod:" << product << endl << endl;

// 	return (root->val + l + r) ;
// }
// int maxProduct(BinaryTreeNode<int>* root)
// {

// 	ll sum  = preorder(root);
// 	ll k = helper(root, sum);
// 	return (product) % M;
// }

int sum = -9999;
int helper(BinaryTreeNode<int>* root)
{
	if (!root)
		return 0;
	int l = helper(root->left);
	int r = helper(root->right);
	int m1 = max(root->val , max(l, r) + root->val);
	int m2 = max(m1 , root->val + l + r);

	cout << "root->val: " << root->val << " ,m1:" << m1 << "  , m2:" << m2 << endl;

	sum = max(sum,  m2);
	return m1;
}
int maxsumpath(BinaryTreeNode<int>* root)
{
	int k = helper(root);
	return sum;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// preorder(root);
	// int t = 2;

	BinaryTreeNode<int>* root = takeInput();
	cout << maxsumpath(root) << endl;



	return 0;
}