#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, int>>> vvpii;

void dijkstra(vvpii& gr, int start)
{
	vector<bool> visited((int)gr.size());
	vector<int> paths((int)gr.size(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, start });
	paths[start] = 0;

	while (!q.empty())
	{
		pair<int, int> top = q.top();
		q.pop();

		visited[top.second] = true;
		for (auto child : gr[top.second])
		{
			if (!visited[child.second] && paths[top.second] + child.first < paths[top.second])
			{
				paths[child.second] = paths[top.second] + child.first;
				q.push({ paths[child.second], child.second });
			}
		}
	}
	
	int size = paths.size();
	for (int i = 0; i < size; i++)
	{
		if (i != start)
		{
			if (paths[i] = INT_MAX)
				cout << -1 << " ";
			else
				cout << paths[i] << " ";
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vvpii gr(n + 1);
	int v, w, t;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> w >> t;
		gr[v].push_back({ t, w });
		gr[w].push_back({ t, v });
	}

	int start;
	cin >> start;

	dijkstra(gr, start);

	return 0;
}
