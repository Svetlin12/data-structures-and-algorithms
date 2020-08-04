#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

string longestPalindrome(string s) {
    vi positions;
    int positionsSize = 2 * s.size() + 1, current = 0;
    positions.reserve(positionsSize);
    while (current != positionsSize) {
        int left = current / 2 - 1, right = current / 2, len = 0;
        if (current % 2 != 0) {
            left = current / 2 - 1;
            right = current / 2 + 1;
            len = 1;
        }
        while (left >= 0 && right < positions.size()) {
            if (s[left] != s[right]) {
                break;
            }
            len += 2;
            left--;
            right++;
        }
        positions.push_back(len);
        current++;
    }

    int max = INT_MIN;
    int pos = 0;
    current = 0;
    for (int i : positions) {
        if (max < i) {
            max = i;
            pos = current;
        }
        current++;
    }

    return s.substr((pos - max) / 2, max);
}

int main() {
    string s = longestPalindrome("abababa");
    cout << s << endl;
    return 0;
}
