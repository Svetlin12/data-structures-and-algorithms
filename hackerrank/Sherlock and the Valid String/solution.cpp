#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string isValid(string s) {
	vector<int> freq(26, 0);
	for (char& c : s)
		freq[c - 'a']++;

	sort(freq.begin(), freq.end());

	int ptr = 0;
	while (freq[ptr] == 0)
		ptr++;

	int maxFreq = freq[25];
	int minFreq = freq[ptr];

	if (maxFreq - minFreq == 0 || (maxFreq - minFreq == 1 && maxFreq > freq[24]) || (minFreq == 1 && freq[ptr + 1] == maxFreq))
		return "YES";

	return "NO";
}

int main() {
	string s;
	cin >> s;

	cout << isValid(s);

	return 0;
}
