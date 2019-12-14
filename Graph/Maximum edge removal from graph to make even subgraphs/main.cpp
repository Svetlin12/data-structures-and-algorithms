#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Graph
{
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    int v, e;
    
    void clearVisited()
    {
        visited.assign(v + 1, false);
    }
    
    int dfs(int curr, int& result)
    {
        visited[curr] = true;
        int components = 0;
        
        for (auto child : adj[curr])
        {
            if (!visited[child])
            {
                int subtreeNodesCount = dfs(child, result);
                if (subtreeNodesCount % 2 == 0)
                    result++;
                components += subtreeNodesCount;
            }
        }
        return components + 1;
    }
    
public:
    
    Graph(int v) : v(v), e(0)
    {
        adj.resize(v + 1);
    }
    
    void addEdge(int v1, int v2)
    {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        e++;
    }
    
    int maxComponents()
    {
        clearVisited();
        int result = 0;
        int start;
        for (int i = 1; i < v + 1; i++)
        {
            if (adj[i].size() != 0)
            {
                start = i;
                break;
            }
        }
        
        dfs(start, result);
        return result;
    }  
};

int main() {
    int v, e;
    cin >> v >> e;
    
    pair<int, int> p;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        cin >> p.first >> p.second;
        g.addEdge(p.first, p.second);
    }
    
    cout << g.maxComponents();
    
    return 0;
}
