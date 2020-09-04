#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// sort string s alphabetically
void reorderString(string& s) {
    vector<int> chars = vector<int>(26);

    for (int i = 0; i < s.size(); i++)
        chars[s[i] - 'a']++;

    int cnt = 0;
    for (int i = 0; i < chars.size(); i++) {
        while (chars[i] != 0) {
            s[cnt++] = i + 'a';
            chars[i]--;
        }
    }
}

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> strings;

    int cnt = 0;
    for (int len = 1; len < s.size(); len++) {
        for (int start = 0; start <= s.size() - len; start++) {
            string str = s.substr(start, len);
            reorderString(str);
            if (strings.find(str) != strings.end()) {
                cnt += strings[str];
                strings[str]++; // we have met that string once more
            }
            else
                strings[str] = 1;
        }
    }
    return cnt;
}

int main() {
    int tests;
    cin >> tests;

    string input;
    for (int i = 0; i < tests; i++) {
        cin >> input;
        cout << sherlockAndAnagrams(input) << endl;
    }
    return 0;
}
