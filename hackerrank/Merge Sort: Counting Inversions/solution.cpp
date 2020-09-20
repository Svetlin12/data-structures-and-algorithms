#include <iostream>
#include <vector>

using namespace std;

long merge(vector<int>& arr, int left, int middle, int right) {
    int sizeL = middle - left + 1;
    int sizeR = right - middle;

    vector<int> l(sizeL);
    vector<int> r(sizeR);

    for (int i = 0; i < sizeL; i++)
        l[i] = arr[i + left];

    for (int i = 0; i < sizeR; i++)
        r[i] = arr[i + middle + 1];

    int leftPtr = 0, rightPtr = 0, start = left;
    long swapsCnt = 0;

    while (leftPtr < sizeL && rightPtr < sizeR) {
        if (l[leftPtr] <= r[rightPtr])
            arr[start++] = l[leftPtr++];
        else {
            arr[start++] = r[rightPtr++];
            swapsCnt += sizeL - leftPtr;
        }
    }

    while (leftPtr < sizeL)
        arr[start++] = l[leftPtr++];

    while (rightPtr < sizeR)
        arr[start++] = r[rightPtr++];

    return swapsCnt;
}

long mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return 0;

    long swapsCnt = 0;

    int middle = (left + right) / 2;
    swapsCnt += mergeSort(arr, left, middle);
    swapsCnt += mergeSort(arr, middle + 1, right);
    swapsCnt += merge(arr, left, middle, right);

    return swapsCnt;
}

long countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    int d;
    cin >> d;

    vector<int> dataset;
    int num;
    for (int i = 0; i < d; i++) {
        int n;
        cin >> n;

        dataset.reserve(n);
        for (int i = 0; i < n; i++) {
            cin >> num;
            dataset.push_back(num);
        }

        cout << countInversions(dataset) << endl;

        dataset.clear();
    }

    return 0;
}
