#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<long long>& arr, long long x)
{
    int start = 0;
    int end = (int)arr.size();

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (arr[middle] < x)
            start = middle + 1;
        else if (arr[middle] > x)
            end = middle - 1;
        else
            return true;
    }

    return false;
}

int pairs(long long k, vector<long long>& arr) {
    int size = (int)arr.size();
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (binarySearch(arr, arr[i] + k))
            counter++;
    }
    return counter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int k;
    cin >> k;

    vector<long long> vec(N);

    int number;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        vec[i] = number;
    }

    sort(vec.begin(), vec.end());
    cout << pairs(k, vec);

    return 0;
}
