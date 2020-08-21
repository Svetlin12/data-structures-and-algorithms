#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
    if (p.empty())
        return s.empty();

    // check if first characters match or if first character of pattern is .
    bool match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

    // if the beginning of the current pattern starts with a* for example, test if the string contains a's or if it does,
    // remove the first occurrence and so on
    if (p.size() >= 2 && p[1] == '*') {
        return isMatch(s, p.substr(2, p.size() - 2)) || (match && isMatch(s.substr(1, s.size() - 1), p));
    }
    else {
        // if the pattern contains only a simple character then remove it from the beginning and check for the remaining substring
        return match && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
    }
}

int main() {

    cout << isMatch("aaa", "ab*a*c*a");

    return 0;
}
