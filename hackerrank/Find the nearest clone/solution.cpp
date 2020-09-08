#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start) {
	vector<bool> visited(graph.size());
	vector<int> lengths(graph.size());
	lengths[start] = 0;
	visited[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto& child : graph[curr]) {
			if (!visited[child]) {
				visited[child] = true;
				q.push(child);
				lengths[child] = lengths[curr] + 1;
			}
		}
	}

	return lengths;
}

int main() {

	int n, e;
	cin >> n >> e;

	vector<vector<int>> graph(n + 1);
	pair<int, int> p;
	for (int i = 0; i < e; i++) {
		cin >> p.first >> p.second;
		graph[p.first].push_back(p.second);
		graph[p.second].push_back(p.first);
	}

	vector<int> colors(n + 1);
	int color;
	for (int i = 1; i <= n; i++) {
		cin >> color;
		colors[i] = color;
	}

	cin >> color;

	int start = 0;
	while (start < colors.size() && colors[start] != color)
		start++;

	if (start == colors.size()) {
		cout << "-1" << endl;
		return 0;
	}

	vector<int> dist = bfs(graph, start);
	int minDist = -1;

	for (int i = 0; i < dist.size(); i++) {
		if (i != start && colors[i] == color) {
			if (minDist == -1)
				minDist = dist[i];
			else
				minDist = min(minDist, dist[i]);
		}
	}

	cout << minDist << endl;

	return 0;
}
