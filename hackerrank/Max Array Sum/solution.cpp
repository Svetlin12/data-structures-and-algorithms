#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long maxSubsetSum(vector<int>& arr) {
	// we can use the fact that the maximum subarray sum of an array of negative values is 0 (the empty subarray)
	arr[0] = max(arr[0], 0);
	if (arr.size() == 1) return arr[0];

	// prepare for the iteration
	// note that arr[i] contains sum value
	arr[1] = max(arr[0], arr[1]);

	for (int i = 2; i < arr.size(); i++)
		// each next value (after arr[0] and arr[1]) can decide whether to keep the non-sequential sum arr[i] + arr[i - 2]
		// or to get the sum of the previous value arr[i - 1] (based on which value is bigger)
		arr[i] = max(arr[i - 1], arr[i] + arr[i - 2]);

	// the last element will contain the maximum subarray sum
	return arr[arr.size() - 1];
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxSubsetSum(arr) << endl;

	return 0;
}
