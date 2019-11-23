#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Heap
{
private:

	vi vec;

	void resize()
	{
		vi newVec;
		int cap = capacity();
		newVec.resize(2 * cap);
		for (int i = 0; i < cap; i++)
			newVec[i] = vec[i];
		vec.clear();
		vec = newVec;
	}

	int size()
	{
		return (int)vec.size();
	}

	int capacity()
	{
		return (int)vec.capacity();
	}

	bool isFull()
	{
		return size() == capacity();
	}

	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * i + 2;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void siftUp(int ind)
	{
		if (ind == 0)
			return;

		int parentInd = parent(ind);
		if (vec[ind] > vec[parentInd])
		{
			swap(vec[ind], vec[parentInd]);
			siftUp(parentInd);
		}
	}

	void siftDown(int ind)
	{
		int leftInd = left(ind);
		if (leftInd >= size())
			return;
		if (leftInd + 1 < size())
		{
			if (vec[ind] < max(vec[leftInd], vec[leftInd + 1]))
			{
				if (vec[leftInd] > vec[leftInd + 1])
				{
					swap(vec[leftInd], vec[ind]);
					siftDown(leftInd);
				}
				else
				{
					swap(vec[leftInd + 1], vec[ind]);
					siftDown(leftInd + 1);
				}
			}
		}
		else
		{
			if (vec[ind] < vec[leftInd])
			{
				swap(vec[ind], vec[leftInd]);
			}
		}
	}

public:

	Heap()
	{
		vec.resize(1000);
	}
	
	// O(NlogN)
	void add(int value)
	{
		if (isFull())
			resize();

		vec[size() - 1] = value;
		siftUp(size() - 1);
	}

	// O(N)
	void buildFloyd(int input[], int n)
	{
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			vec[i] = input[i];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			siftDown(i);
		}
	}

	void extract()
	{
		swap(vec[0], vec[size() - 1]);
		vec.erase(vec.begin() + size() - 1);
		siftDown(0);
	}

	int peek()
	{
		return vec[0];
	}
};

int main()
{
	Heap h;
	h.add(3);
	h.add(2);
	h.add(1);
	h.add(15);
	h.add(5);
	h.add(4);
	h.add(45);

	cout << h.peek() << endl;
	h.extract();
	cout << h.peek() << endl;

	Heap h1;
	int arr[] = { 3, 2, 1, 15, 5, 4, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);

	h1.buildFloyd(arr, size);

	cout << h1.peek() << endl;
	h1.extract();
	cout << h1.peek() << endl;

	return 0;
}
