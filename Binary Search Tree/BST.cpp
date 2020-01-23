#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;

	node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:

	node *root;

	node* insert_rec(int data, node* root)
	{
		if (root == nullptr)
			return new node(data);

		if (root->data < data)
			root->right = insert_rec(data, root->right);
		else if (root->data > data)
			root->left = insert_rec(data, root->left);
		return root;
	}

	node* remove_rec(int data, node* root)
	{
		if (root == nullptr)
			return root;

		if (root->data < data)
			root->right = remove_rec(data, root->right);
		else if (root->data > data)
			root->left = remove_rec(data, root->left);
		else
		{
			if (root->right == nullptr)
			{
				node* tmp = root->left;
				delete root;
				return tmp;
			}
			else if (root->left == nullptr)
			{
				node* tmp = root->right;
				delete root;
				return tmp;
			}

			node* temp = root->right;
			while (temp->left != nullptr)
				temp = temp->left;

			root->data = temp->data;

			root->right = remove_rec(temp->data, root->right);
		}
		return root;
	}

	void print_rec(node* node)
	{
		if (node)
		{
			print_rec(node->left);
			cout << node->data << " ";
			print_rec(node->right);
		}
	}

	bool search_rec(node* node, int data)
	{
		if (node == nullptr)
			return 0;
		if (node->data == data)
			return 1;

		if (node->data > data)
			return search_rec(node->left, data);
		else if (node->data < data)
			return search_rec(node->right, data);
	}

	node* getNode_rec(node* node, int data)
	{
		if (node == nullptr || node->data == data)
			return node;

		if (node->data > data)
			return getNode_rec(node->left, data);
		else if (node->data < data)
			return getNode_rec(node->right, data);
	}

	int getHeight_rec(node* root)
	{
		if (!root)
			return 0;

		int leftH = getHeight_rec(root->left);
		int rightH = getHeight_rec(root->right);

		if (leftH > rightH)
			return leftH + 1;
		else
			return rightH + 1;
	}

	bool isBST_rec(node* root, int min, int max)
	{
		if (root == nullptr)
			return 1;

		if (root->data < min || root->data > max)
			return 0;

		return isBST_rec(root->left, min, root->data - 1) && isBST_rec(root->right, root->data + 1, max);
	}

	// lowest common ancestor
	node* lca_rec(node* root, int v1, int v2)
	{
		if (root == nullptr)
			return nullptr;

		if (root->data < v1 && root->data < v2)
			return lca_rec(root->right, v1, v2);
		else if (root->data > v1 && root->data > v2)
			return lca_rec(root->left, v1, v2);

		return root;
	}

	void dfsToVec(node* root, vector<int>& v)
	{
		if (root)
		{
			dfsToVec(root->left, v);
			v.push_back(root->data);
			dfsToVec(root->right, v);
		}
	}

	void findMinMax(node* root, int& min, int& max, int h)
	{
		if (root == nullptr)
			return;

		if (h < min) 
			min = h;
		if (h > max)
			max = h;

		findMinMax(root->left, min, max, h - 1);
		findMinMax(root->right, min, max, h + 1);
	}

	void printVertically(node* root, int target, int h)
	{
		if (root == nullptr)
			return;

		if (h == target)
			cout << root->data << " ";

		printVertically(root->left, target, h - 1);
		printVertically(root->right, target, h + 1);
	}

	node* attach(vector<int>& nums, int from, int to)
	{
		if (from > to || from < 0 || to >= (int)nums.size())
			return nullptr;

		int middle = (from + to) / 2;
		int leftPortion = middle - 1;
		int rightPortion = middle + 1;
		node* tmp = new node(nums[middle]);
		tmp->left = attach(nums, from, leftPortion);
		tmp->right = attach(nums, rightPortion, to);
		return tmp;
	}

	void topView_rec(node* root, int visibility, vector<node*>& vec, int offset, vector<int>& height, int currHeight)
	{
		if (root == nullptr)
			return;

		if (vec[visibility + offset] == nullptr)
		{
			vec[visibility + offset] = root;
			height[visibility + offset] = currHeight;
		}
		else
			if (height[visibility + offset] > currHeight)
			{
				vec[visibility + offset] = root;
				height[visibility + offset] = currHeight;
			}

		topView_rec(root->left, visibility - 1, vec, offset, height, currHeight + 1);
		topView_rec(root->right, visibility + 1, vec, offset, height, currHeight + 1);
	}

public:

	BinarySearchTree() : root(nullptr){}

	void insert(int data)
	{
		root = insert_rec(data, root);
	}

	void remove(int data)
	{
		root = remove_rec(data, root);
	}

	void print()
	{
		print_rec(root);
	}

	bool search(int data)
	{
		return search_rec(root, data);
	}

	node* getNode(int data)
	{
		return getNode_rec(root, data);
	}

	int getHeight()
	{
		return getHeight_rec(root) - 1;
	}

	bool isBST()
	{
		return isBST_rec(root, INT_MIN, INT_MAX);
	}

	void bst()
	{
		if (root == nullptr)
			return;

		queue<node*> q;
		q.push(root);

		while (!q.empty())
		{
			node* tmp = q.front();
			cout << tmp->data << " ";
			q.pop();

			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
	}

	void dfs()
	{
		print();
	}

	node* lca(int v1, int v2)
	{
		return lca_rec(root, v1, v2);
	}

	int kthSmallestElement(int k)
	{
		vector<int> v;
		v.reserve(100000);
		dfsToVec(root, v);
		return v[k - 1];
	}

	void verticalOrder()
	{
		int min = 0, max = 0;
		findMinMax(root, min, max, 0);

		for (int i = min; i <= max; i++)
		{
			printVertically(root, i, 0);
			cout << endl;
		}
	}

	void topView()
	{
		vector<node*> vec(1000, nullptr);
		vector<int> height(1000, 0);
		int visibility = 0;
		int offset = 500;
		int currHeight = 0;
		topView_rec(root, visibility, vec, offset, height, currHeight);

		for (int i = 0; i < 1000; i++)
		{
			if (vec[i] != nullptr)
				cout << vec[i]->data << " ";
		}
	}
};

int main()
{
	// 1 14 3 7 4 5 15 6 13 10 11 2 12 8 9
	BinarySearchTree b;
	b.insert(1);
	b.insert(14);
	b.insert(3);
	b.insert(7);
	b.insert(4);
	b.insert(5);
	b.insert(15);
	b.insert(6);
	b.insert(13);
	b.insert(10);
	b.insert(11);
	b.insert(2);
	b.insert(12);
	b.insert(8);
	b.insert(9);

	b.topView();

	return 0;
}
