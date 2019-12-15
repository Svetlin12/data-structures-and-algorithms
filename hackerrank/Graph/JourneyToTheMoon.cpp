#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:

    vector<vector<int>> adj;
    vector<bool> visited;
    int v, e;

    void dfsUtil(int curr, int& count)
    {
        visited[curr] = true;
        count++;

        for (auto child : adj[curr])
            if (!visited[child])
                dfsUtil(child, count);
    }

public:

    Graph(int v) : v(v), e(0)
    {
        adj.resize(v + 1);
        visited.resize(v + 1);
    }

    void addEdge(int v1, int v2)
    {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        e++;
    }

    int dfs()
    {
        int verticesInComponent = 0;
        int count = 0;
        for (int i = 0; i < v + 1; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, verticesInComponent);
                count += verticesInComponent * (verticesInComponent - 1);
                verticesInComponent = 0;
            }
        }
        return count;
    }

};

int main()
{
    long long n, p;
    cin >> n >> p;

    Graph g(n);

    pair<int, int> input;
    for (int i = 0; i < p; i++)
    {
        cin >> input.first >> input.second;
        g.addEdge(input.first, input.second);
    }

    long long maxEdgesNums = n * (n - 1);
    cout << (maxEdgesNums - g.dfs()) / 2;

    return 0;
}
