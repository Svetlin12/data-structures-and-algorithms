#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <list>

using namespace std;

int prims_algorithm(const vector<list<pair<int, int>>>& gr, int v)
{
	unordered_set<int> S;
	S.insert(v);

	int total_weight = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (const auto& child : gr[v])
		pq.push(child);

	while (S.size() != (int)gr.size() && !pq.empty())
	{
		pair<int, int> edge = pq.top();
		pq.pop();

		int weight = edge.first;
		int u = edge.second;

		if (S.count(u) == 0)
		{
			total_weight += weight;
			S.insert(u);

			for (const auto& child : gr[u])
				pq.push(child);
		}
	}

	return total_weight;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<list<pair<int, int>>> gr(n + 1);

	int v1, v2, w;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		gr[v1].push_back({ w, v2 });
		gr[v2].push_back({ w, v1 });
	}

	int start;
	cin >> start;

	cout << prims_algorithm(gr, start);

	return 0;
}
