#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

typedef vector<list<int>> vli;
typedef vector<bool> vb;

class Graph
{
private:

    vli adj;
    int v, e;

    void dfsUtil(vb& visited, int curr)
    {
        visited[curr] = true;
        cout << curr << " ";
        // add additional checks or return type for different problems
        for (auto i : adj[curr])
            if (!visited[i])
                dfsUtil(visited, i);
    }

public:

    Graph(int v = 0) : v(v), e(0)
    {
        adj.resize(v + 1);
    }

    void dfs(int start)
    {
        vb visited(v + 1, 0);
        dfsUtil(visited, start);
    }

    void bfs(int start)
    {
        vb visited(v + 1, 0);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int level = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (auto i : adj[curr])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }

            level++;
        }
    }

    void addEdge(int v1, int v2)
    {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        e++;
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
