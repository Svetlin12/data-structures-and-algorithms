#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int binarySearch(int start, int end, vector<int>& arr, int target) {
	int ans = -1;
	while (start <= end) {
		int middle = (start + end) / 2;
		if (arr[middle] <= target) {
			ans = middle;
			start = middle + 1;
		}
		else
			end = middle - 1;
	}
	return ans + 1;
}

long triplets(vector<int>& a, vector<int>& b, vector<int>& c) {
	long ans = 0;
	for (int i = 0; i < b.size(); i++) {
		// search how many elements in a and c b[i] is bigger than or equal to
		long aSize = binarySearch(0, a.size() - 1, a, b[i]);
		long cSize = binarySearch(0, c.size() - 1, c, b[i]);

		// there are exactly (aSize * cSize) triplets that can be formed (for each element from a that is less or equal to 
		// b[i], we can traverse through the elements from c that are less than or equal to b[i], hence aSize * cSize)
		ans += aSize * cSize;
	}
	return ans;
}

int main() {
	int lena, lenb, lenc;
	cin >> lena >> lenb >> lenc;

	vector<int> a, b, c;
	a.reserve(lena);
	b.reserve(lenb);
	c.reserve(lenc);
	int num;
	unordered_map<int, bool> distinctA; // stores the distinct values for A
	unordered_map<int, bool> distinctB; // stores the distinct values for B
	unordered_map<int, bool> distinctC; // stores the distinct values for C

	for (int i = 0; i < lena; i++) {
		cin >> num;
		if (!distinctA[num])
			a.push_back(num);
		distinctA[num] = true;
	}

	for (int i = 0; i < lenb; i++) {
		cin >> num;
		if (!distinctB[num])
			b.push_back(num);
		distinctB[num] = true;
	}

	for (int i = 0; i < lenc; i++) {
		cin >> num;
		if (!distinctC[num])
			c.push_back(num);
		distinctC[num] = true;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	cout << triplets(a, b, c) << endl;

	return 0;
}
