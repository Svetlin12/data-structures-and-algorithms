#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:

	vector<vector<int>> adj;
	vector<bool> visited;
	int v, e;
	vector<vector<pair<int, int>>> G; // first - distance, second - number of node; for use in Djikstra;

	void clearVisited()
	{
		visited.assign(v + 1, false);
	}

	void dfsUtil(int current, vector<bool>& visited)
	{
		visited[current] = true;

		for (auto child : adj[current])
			if (!visited[child])
				dfsUtil(child, visited);
	}

	bool isCyclicUtil(int curr, int parent)
	{
		visited[curr] = true;

		for (auto child : adj[curr])
		{
			if (visited[child] && child != parent)
				return true;
			else if (!visited[child] && isCyclicUtil(child, curr))
				return true;
		}

		return false;
	}

public:

	Graph(int v) : v(v), e(0)
	{
		adj.resize(v + 1);
		visited.resize(v + 1, false);
		G.resize(v + 1);
	}

	void addEdge(int v1, int v2)
	{
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		e++;
	}

	void dfs(int start)
	{
		clearVisited();
		dfsUtil(start, visited);
	}

	void bfs(int start)
	{
		queue<int> q;
		q.push(start);
		clearVisited();
		visited[start] = true;

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();

			for (auto child : adj[curr])
			{
				if (!visited[child])
				{
					q.push(child);
					visited[child] = true;
				}
			}
		}
	}

	void bfsLevel(int start, int level)
	{
		queue<int> q;
		q.push(start);
		clearVisited();
		visited[start] = true;

		int size = 1;
		int currLevel = 0;

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			size--;

			if (currLevel = level)
				cout << "visited: " << curr << "\n";

			for (auto child : adj[curr])
			{
				if (!visited[child])
				{
					q.push(child);
					visited[child] = true;
				}
			}

			if (size == 0)
			{
				size = q.size();
				currLevel++;
			}
		}
	}

	bool isCyclic(int start)
	{
		clearVisited();
		return isCyclicUtil(start, start);
	}

	void dijkstra(int start)
	{
		vector<int> d(G.size(), INT_MAX);
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, start });

		while (!pq.empty())
		{
			int dist = pq.top().first;
			int v = pq.top().second;
			pq.pop();

			d[v] = dist;
			for (auto child : G[v])
				pq.push({ dist + child.second, child.first });
		}
	}
};

int main()
{
	int v, e, i, u, w;

	cin >> v >> e;

	Graph g(v);

	pair <int, int> p;
	for (int i = 0; i < e; i++)
	{
		cin >> p.first >> p.second;
		g.addEdge(p.first, p.second);
	}

	cout << "DFS: ";
	g.dfs(1);
	cout << "\nBFS: ";
	g.bfs(1);

	return 0;
}
