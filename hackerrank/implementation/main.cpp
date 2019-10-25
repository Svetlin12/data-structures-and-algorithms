#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// note that this implementation works even if the array from the input has multiple elements that are the same

typedef vector<int> vi;

int binarySearch(vi& vec, int x)
{
    int size = (int)vec.size() - 1;
    int start = 0;
    int end = size;
    int index = -1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (vec[middle] == x)
        {
            index = middle;
            break;
        }
        else if (vec[middle] > x)
            end = middle - 1;
        else
            start = middle + 1;
    }

    if (index == -1)
        return 0;

    int counter = 1;
    int leftSide = index - 1;
    int rightSide = index + 1;

    if (leftSide != 0)
        while (vec[leftSide--] == x)
        {
            counter++;
            if (leftSide == 0)
                break;
        }

    if (rightSide != size)
        while (vec[rightSide++] == x)
        {
            counter++;
            if (rightSide == size)
                break;
        }

    return counter;
}

int countPairs(vi& vec, int k)
{
    int size = (int)vec.size();
    int counter = 0;
    for (int i = 0; i < size; i++)
        counter += binarySearch(vec, vec[i] + k);
    return counter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int k;

    cin >> N >> k;

    vi vec(N);

    int number;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        vec[i] = number;
    }

    sort(vec.begin(), vec.end());
    cout << countPairs(vec, k);

    return 0;
}