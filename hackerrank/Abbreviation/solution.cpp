#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isUppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

char uppercased(char c) {
    if (isUppercase(c)) return c;
    return c - 32;
}

string abbreviation(const string& a, const string& b) {
    // dp[i][j] = 1 if the substring of length j from b can be formed with the first i characters from a, dp[i][j] = 0 otherwise
    vector<vector<bool>> dp(a.size() + 1, vector<bool>(b.size() + 1));
    
    dp[0][0] = true;

    for (int i = 0; i < a.size(); i++) {
        char fromA = a[i];
        for (int j = 0; j <= b.size(); j++) {
            // check only the cases where we can form a substring from b
            if (dp[i][j]) {
                char fromB = b[j];
                
                // if fromA is uppercase and equals fromB, then we can form a substring of length j + 1 from b with the first i + 1 characters from a
                if (isUppercase(fromA)) {
                    if (fromA == fromB)
                        dp[i + 1][j + 1] = true;
                }
                else {
                    // if fromA is the lowercase version of fromB, then either we can form a substring of length j or length j + 1 from b with the first i + 1 chars from a
                    // length j: we check if there is another character like fromB after fromA in the string a (so there won't be need to uppercase fromA and instead delete it)
                    // length j + 1: we assume there isn't another character like fromB after fromA in a and we therefore uppercase A
                    if (uppercased(fromA) == fromB) {
                        dp[i + 1][j] = true;
                        dp[i + 1][j + 1] = true;
                    }
                    else
                        dp[i + 1][j] = true; // we essentially delete this char
                }
            }
        }
    }

    if (dp[a.size()][b.size()])
        return "YES";
    else return "NO";
}

int main() {
    int q;
    cin >> q;

    string modify, match;
    for (int i = 0; i < q; i++) {
        cin >> modify >> match;
        cout << abbreviation(modify, match) << endl;
    }

    return 0;
}
