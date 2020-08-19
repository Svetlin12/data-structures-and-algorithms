#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void dfs(unordered_map<string, vector<pair<string, bool>>>& um, string& curr, vector<string>& ans, int targetSize) {
    if (ans.size() == targetSize) return;
    ans.push_back(curr);

    for (int i = 0; i < um[curr].size(); i++) {
        if (!um[curr][i].second) {
            um[curr][i].second = true;
            dfs(um, um[curr][i].first, ans, targetSize);
            um[curr][i].second = false;
        }
    }

    if (ans.size() != targetSize)
        ans.pop_back();
    else return;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<pair<string, bool>>> um;

    for (auto& vec : tickets) {
        string from = vec[0];
        string to = vec[1];
        um[from].push_back({to, false});
    }

    for (auto it = um.begin(); it != um.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    string start = "JFK";
    vector<string> ans;
    dfs(um, start, ans, tickets.size() + 1);
    return ans;
}

int main() {
    vector<vector<string>> v = { {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} };
    vector<vector<string>> v2 = { {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> v3 = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> res = findItinerary(v2);
    for (auto& s : res) {
        cout << s << "->";
    }

    cout << endl;

    return 0;
}
