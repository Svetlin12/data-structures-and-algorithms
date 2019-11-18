#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct node
{
	int data;
	int height;
	node *left, *right;

	node(int data) : data(data), height(0), left(nullptr), right(nullptr){}
};

class AVLTree
{
private:

	node *root;

	int getHeight(node* n)
	{
		if (n == nullptr)
			return -1;
		return n->height;
	}

	int getBalance(node *root)
	{
		if (!root)
			return 0;
		return getHeight(root->left) - getHeight(root->right);
	}

	node* rightRotation(node* n)
	{
		node* left = n->left;
		node* rightSubtree = left->right;

		left->right = n;
		n->left = rightSubtree;

		// update the height of the node we performed the rotation on and its left child
		n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
		left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

		return left;
	}

	node* leftRotation(node* n)
	{
		node* right = n->right;
		node* leftSubtree = right->left;

		right->left = n;
		n->right = leftSubtree;

		// update the height of the node we performed the rotation on and its right child
		n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
		right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

		return right;
	}

	node* insert_rec(node* root, int data)
	{
		if (root == nullptr)
			return new node(data);

		if (data > root->data)
			root->right = insert_rec(root->right, data);
		else if (data < root->data)
			root->left = insert_rec(root->left, data);
		else
			return root;

		// update the height of the nodes
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));

		int balance = getBalance(root);
		int leftBalance = 0;
		int rightBalance = 0;
		if (balance > 1)
			leftBalance = getBalance(root->left);
		if (balance < -1)
			rightBalance = getBalance(root->right);

		if (balance > 1 && leftBalance >= 0)
			return rightRotation(root);

		if (balance > 1 && leftBalance < 0)
		{
			root->left = leftRotation(root->left);
			return rightRotation(root);
		}

		if (balance < -1 && rightBalance <= 0)
			return leftRotation(root);

		if (balance < -1 && rightBalance > 0)
		{
			root->right = rightRotation(root->right);
			return leftRotation(root);
		}

		return root;
	}

	void print_rec(node* root)
	{
		if (root)
		{
			print_rec(root->left);
			cout << root->data << " ";
			print_rec(root->right);
		}
	}

	node* deleteNode_rec(node* root, int data)
	{
		if (root == nullptr)
			return root;

		if (root->data < data)
			root->right = deleteNode_rec(root->right, data);
		else if (root->data > data)
			root->left = deleteNode_rec(root->left, data);
		else
		{
			if (root->right == nullptr)
			{
				node* tmp = root->left;
				delete root;
				root = tmp;
			}
			else if (root->left == nullptr)
			{
				node* tmp = root->right;
				delete root;
				root = tmp;
			}
			else
			{
				node* tmp = root->right;
				while (tmp && tmp->left)
					tmp = tmp->left;

				root->data = tmp->data;
				root->right = deleteNode_rec(root->right, tmp->data);
			}
		}

		if (root == nullptr)
			return root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));

		int balance = getBalance(root);
		int leftHeight = 0;
		int rightHeight = 0;
		if (balance > 1)
			leftHeight = getBalance(root->left);
		else if (balance < -1)
			rightHeight = getBalance(root->right);

		if (balance > 1 && leftHeight >= 0)
			return rightRotation(root);
		if (balance > 1 && leftHeight < 0)
		{
			root->left = leftRotation(root->left);
			return rightRotation(root);
		}
		if (balance < -1 && rightHeight <= 0)
			return leftRotation(root);
		if (balance < -1 && rightHeight > 0)
		{
			root->right = rightRotation(root->right);
			return leftRotation(root);
		}

		return root;
	}

	bool search_rec(int data, node* root)
	{
		if (root == nullptr)
			return false;
		if (root->data == data)
			return true;

		if (root->data < data)
			return search_rec(data, root->right);
		else if (root->data > data)
			return search_rec(data, root->left);
	}

	node* searchNode(int data, node* root)
	{
		if (root == nullptr)
			return root;
		if (root->data == data)
			return root;

		if (root->data < data)
			return searchNode(data, root->right);
		else if (root->data > data)
			return searchNode(data, root->left);
	}

public:

	AVLTree() : root(nullptr) {}

	void insert(int data)
	{
		root = insert_rec(root, data);
	}

	void print()
	{
		print_rec(root);
	}

	void deleteNode(int data)
	{
		root = deleteNode_rec(root, data);
	}

	bool search(int data)
	{
		return search_rec(data, root);
	}

	int getDepth(int data)
	{
		return getHeight(searchNode(data, root));
	}
};

int main()
{
	// implement test cases here

	return 0;
}
