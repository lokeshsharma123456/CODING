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
void preorder(BinaryTreeNode<int>*root)
{
	if (!root)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}
int helper(BinaryTreeNode<int>* root, int min_val , int max_val)
{

	//return INT_MAX
	if (!root)
		return max_val - min_val;
	//root->val - x = always negative if root->val>0 so it will work
	int x , y;
	//if leaf


	min_val = min(min_val , root->val);
	max_val = max(max_val , root->val);

	// cout << root->val   << " min:" << min_val << " , mx:" << max_val << endl;
	x = helper(root->left , min_val , max_val);
	y = helper(root->right , min_val , max_val);
	// cout << root->val << " x:" << x << " y:" << y << " min:" << min_val << " , mx:" << max_val << endl;
	return max(x, y);
}


int maxAncestorDiff(BinaryTreeNode<int>* root)
{
	int min_val = 100000;
	int max_val = 0;
	int k = helper(root , min_val , max_val);
	return k;

}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	BinaryTreeNode<int>* root = takeInput();
	// preorder(root);
	cout << maxAncestorDiff(root) << endl;


	return 0;
}