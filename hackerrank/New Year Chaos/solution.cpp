#include <iostream>
#include <vector>
using namespace std;

void minimumBribes(vector<int>& q) {
	int bribesCnt = 0;
	for (int i = q.size() - 1; i >= 0; i--) {
		// check if on the i-th position, the number is bigger than it is supposed to be
		// for example: the number on 5-th position is 9 (in q) and on 5-th position starts the number 6
		// so the maximum number that can reach this position is 6 + 2 = 8. This means that 9 bribed 3 times to reach this
		// position
		if (q[i] - (i + 1) > 2) {
			cout << "Too chaotic" << endl;
			return;
		}

		// assuming that the current number q[i] bribed 2 people, his position would be q[i] - 2 (in terms of initial positions)
		// this means that from that index until the current position, if the j-th number is bigger than the i-th, then
		// q[j] bribed q[i] resulting in q[i] going backwards (+1 bribe)
		for (int j = max(0, q[i] - 2); j < i; j++)
			if (q[j] > q[i]) {
				bribesCnt++;
			}
	}

	cout << bribesCnt << endl;
}

int main() {
	int t;
	cin >> t;

	int n, num;
	vector<int> q;
	for (int i = 0; i < t; i++) {
		cin >> n;

		q.reserve(n);
		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push_back(num);
		}

		minimumBribes(q);

		q.clear();
	}

	return 0;
}
