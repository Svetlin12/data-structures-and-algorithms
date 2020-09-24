#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long countTriplets(vector<long>& arr, long r) {
    // stores the count of each occurrence on the left of the current element
    unordered_map<long, long> left;
    
    // stores the count of each occurrence on the right of the current element
    unordered_map<long, long> right;

    // we start from the beginning of arr so every element will be on the right of the current element
    for (long& elem : arr)
        right[elem]++;

    long cnt = 0;
    for (long& elem : arr) {
        // the current element is not going to be part of the count to the right
        right[elem]--;
        
        // if the element is not divisible to r then continue
        if (elem % r != 0) {
            left[elem]++;
            continue;
        }
        
        long prev = elem / r;
        long next = elem * r;
        cnt += left[prev] * right[next];
        left[elem]++;
    }

    return cnt;
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countTriplets(arr, r) << endl;

    return 0;
}
