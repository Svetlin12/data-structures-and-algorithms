class Solution {
public:
    void backtrack(vector<string>& ans, string digits, int current, string str, unordered_map<int, string> m) {
        for (int i = 0; i < m[digits[current] - '0'].size(); i++) {
            str += m[digits[current] - '0'][i];
            if (current == digits.size() - 1) {
                ans.push_back(str);
                str.pop_back();
                continue;
            }
            backtrack(ans, digits, current + 1, str, m);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m = { {2, "abc"}, { 3, "def"}, {4, "ghi"}, {5, "jkl"},
                                         {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> ans;
        backtrack(ans, digits, 0, "", m);
        return ans;
    }
};
