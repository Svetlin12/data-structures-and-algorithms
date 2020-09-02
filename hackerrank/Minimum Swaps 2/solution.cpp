#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int minimumSwaps(vector<int>& vec) {
	// value - index
	unordered_map<int, int> values;

	for (int i = 0; i < vec.size(); i++)
		values[vec[i]] = i;

	int cnt = 0;

	// the trick to this problem is that numbers always start with 1
	int start = 1;

	for (int i = 0; i < vec.size() - 1; i++) {

		// if the number is not in it's right position, get its index in vec, swap the two elements and change the index of 
		// the other number we just swapped
		if (vec[i] != start) {
			int index = values[start];
			swap(vec[index], vec[i]);
			values[vec[index]] = index;
			cnt++;
		}
		start++;
	}

	return cnt;
}

int main() {
	vector<int> nums;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cout << minimumSwaps(nums) << endl;

	return 0;
}
