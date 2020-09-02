#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<long>& machines, long goal, long long days) {
	// total amount of produced products after (days) days
	long total = 0;
	
	for (long i = 0; i < machines.size(); i++)
		total += days / machines[i]; // add the amount each machine can produce for that amount of days

	return goal <= total;
}

// binary search through the answer
long long minTime(vector<long>& machines, long goal) {
	long long rightEnd = machines[0] * goal;
	long long leftEnd = 1;
	long ans = -1;

	while (leftEnd <= rightEnd) {
		long long middle = (rightEnd + leftEnd) / 2;

		if (isValid(machines, goal, middle)) {
			ans = middle;
			rightEnd = middle - 1;
		}
		else
			leftEnd = middle + 1;
	}

	return ans;
}

int main() {
	long n, target;
	cin >> n >> target;

	vector<long> daysToProducePerMachine;
	daysToProducePerMachine.reserve(n);
	long num;
	for (long i = 0; i < n; i++) {
		cin >> num;
		daysToProducePerMachine.push_back(num);
	}

	cout << minTime(daysToProducePerMachine, target) << endl;
	return 0;
}
