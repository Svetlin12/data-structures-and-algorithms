#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

class MaxHeap
{
private:

    vi arr;

    const int parent(int ind)
    {
        return (ind - 1) / 2;
    }

    const int left(int ind)
    {
        return 2 * ind + 1;
    }

    const int right(int ind)
    {
        return 2 * ind + 2;
    }

    const bool hasLeft(int ind)
    {
        return left(ind) < arr.size();
    }

    const bool hasRight(int ind)
    {
        return right(ind) < arr.size();
    }

    void siftUp(int ind)
    {
        if (ind == 0)
            return;

        if (arr[parent(ind)] < arr[ind])
        {
            swap(arr[parent(ind)], arr[ind]);
            siftUp(parent(ind));
        }
    }

    void siftDown(int ind)
    {
        if (!hasLeft(ind))
            return;

        int maxValChild = left(ind);
        if (hasRight(ind) && arr[right(ind)] > arr[maxValChild])
            maxValChild = right(ind);
        if (arr[ind] < arr[maxValChild])
        {
            swap(arr[ind], arr[maxValChild]);
            siftDown(maxValChild);
        }
    }

public:

    MaxHeap()
    {
        arr.reserve(1000);
    }

    void push(int val)
    {
        arr.push_back(val);
        siftUp(arr.size() - 1);
    }

    void pop()
    {
        int size = arr.size();
        if (size == 0)
            return;
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        siftDown(0);
    }

    int top()
    {
        if (arr.size() == 0)
            return -1;
        return arr[0];
    }

    void makeHeap(vi& input)
    {
        int size(input.size()), i;
        arr.resize(size);
        for(i = 0; i < size; ++i)
            arr[i] = input[i];
        for (i = (size / 2) - 1; i >= 0; i--)
            siftDown(i);

        arr.reserve(1000);
    }

};

int main()
{
    MaxHeap m;
    m.push(4);
    m.push(1);
    m.push(10);
    cout << m.top() << endl;
    m.push(20);
    cout << m.top() << endl;
    m.pop();
    cout << m.top() << endl;
    m.pop();
    m.pop();
    cout << m.top() << endl;
    m.pop();
    cout << m.top() << endl;

    vi input;
    for (int i = 0; i < 100; i++)
        input.push_back(i);

    MaxHeap m1;
    m1.makeHeap(input);

    for (int i = 0; i < 100; i++)
    {
        cout << m1.top() << endl;
        m1.pop();
    }

    return 0;
}
