#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct node
{
	vi point;
	node *left, *right;

	node(vi& points) : point(points), left(nullptr), right(nullptr) {}
};

class KDTree
{
private:

	node* root;
	int k;

	node* insertRec(vi& point, node* root, int level)
	{
		if (root == nullptr)
			return new node(point);

		int coordToCompare = level % k;
		
		if (point[coordToCompare] < root->point[coordToCompare])
			root->left = insertRec(point, root->left, level + 1);
		else
			root->right = insertRec(point, root->right, level + 1);

		return root;
	}

	// first and second points
	const bool arePointsSame(vi& fp, vi& sp)
	{
		for (int i = 0; i < k; i++)
			if (fp[i] != sp[i])
				return false;
		return true;
	}

	bool searchPointRec(vi& point, node* root, int level)
	{
		if (root == nullptr)
			return false;
		if (arePointsSame(point, root->point))
			return true;

		int coordToCompare = level % k;

		if (point[coordToCompare] < root->point[coordToCompare])
			return searchPointRec(point, root->left, level + 1);
		
		return searchPointRec(point, root->right, level + 1);
	}

	void printPointsInsideRecRecursive(vi& upperLeft, vi& lowerRight, int level, node* root)
	{
		if (root)
		{
			if (level % 2 == 0)
			{
				if (root->point[0] < upperLeft[0])
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->right);
				else if (root->point[0] > lowerRight[0])
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->left);
				else
				{
					if (root->point[1] <= upperLeft[1] && root->point[1] >= lowerRight[1])
						printf("x = %d y = %d\n", root->point[0], root->point[1]);
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->left);
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->right);
				}
			}
			else
			{
				if (root->point[1] > upperLeft[1])
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->left);
				else if (root->point[1] < lowerRight[1])
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->right);
				else
				{
					if (root->point[0] >= upperLeft[0] && root->point[0] <= lowerRight[0])
						printf("x = %d y = %d\n", root->point[0], root->point[1]);
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->left);
					printPointsInsideRecRecursive(upperLeft, lowerRight, level + 1, root->right);
				}
			}
		}
	}

	void printRec(node* root) const
	{
		if (root)
		{
			printRec(root->left);
			for (int i = 0; i < k; i++)
				cout << root->point[i] << " ";
			cout << endl;
			printRec(root->right);
		}
	}

public:

	KDTree(int k = 1) : k(k) {}

	void insert(vi point)
	{
		root = insertRec(point, root, 0);
	}

	// search a point
	bool searchPoint(vi& point)
	{
		return searchPointRec(point, root, 0);
	}

	// search points inside a rectangle
	// this function only works with 2d tree
	void printPointsInsideRec(vi& upperLeft, vi& lowerRight)
	{
		printPointsInsideRecRecursive(upperLeft, lowerRight, 0, root);
	}
	
	void print() const
	{
		printRec(root);
	}
};

int main()
{
	KDTree k(2);
	k.insert({ 3, 4 });
	k.insert({ 1, 2 });
	k.insert({ 4, 1 });
	k.insert({ -1, 2 });
	k.insert({ 13, 8 });
	k.insert({ -2, 1 });
	k.insert({ 2, 1 });
	k.insert({ 9, 9 });
	k.insert({ 2, 3 });
	k.print();
	vi upperLeft = { 2, 5 };
	vi lowerRight = { 5, 2 };
	k.printPointsInsideRec(upperLeft, lowerRight);
	cout << endl;
	vi point1 = { 2, 1 };
	vi point2 = { 3, 4 };
	vi point3 = { 13, 8 };
	vi point4 = { 2, 2 };
	cout << k.searchPoint(point1) << endl << k.searchPoint(point4) << endl;

	return 0;
}
