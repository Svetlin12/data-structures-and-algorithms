#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> shortest_reach(vector<vector<int>>& graph, int start) {
	vector<int> ans = vector<int>(graph.size(), INT_MAX);
	vector<bool> visited = vector<bool>(graph.size(), 0);
	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		ans[curr.first] = curr.second;

		for (auto& child : graph[curr.first]) {
			if (!visited[child]) {
				q.push({ child, curr.second + 6 });
				visited[child] = true;
			}
		}
	}

	return ans;
}

int main() {
	int numQueries;
	cin >> numQueries;

	for (int i = 0; i < numQueries; i++) {
		int n, m;
		cin >> n >> m;

		pair<int, int> p;
		vector<vector<int>> graph = vector<vector<int>>(n + 1);
		for (int j = 0; j < m; j++) {
			cin >> p.first >> p.second;
			graph[p.first].push_back(p.second);
			graph[p.second].push_back(p.first);
		}

		int start;
		cin >> start;
	
		vector<int> lengths = shortest_reach(graph, start);

		for (int i = 1; i < lengths.size(); i++) {
			if (lengths[i] == 0)
				continue;
			else if (lengths[i] == INT_MAX)
				cout << "-1 ";
			else
				cout << lengths[i] << " ";
		}

		cout << endl;
	}

	return 0;
}
