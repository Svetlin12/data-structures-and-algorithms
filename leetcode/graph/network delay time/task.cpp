class Solution {
private:
    
    vector<bool> visited;
    vector<list<pair<int, int>>> adj;
    vector<int> paths;
    int maxWeight = INT_MIN;
    
public:
    void dijkstra(int start)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        paths[start] = 0;
        
        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            
            visited[top.second] = true;
            for (auto& child : adj[top.second])
            {
                if (!visited[child.second] && paths[top.second] + child.first < paths[child.second])
                {
                    paths[child.second] = paths[top.second] + child.first;
                    pq.push({paths[child.second], child.second});
                }
            }
        }
    }
    
    void convertToAdj(vector<vector<int>>& times)
    {
        int size = (int)times.size();
        
        for (int i = 0; i < size; i++)
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        adj.resize(N + 1);
        visited.resize(N + 1);
        paths.resize(N + 1, INT_MAX);
        convertToAdj(times);
        dijkstra(K);
        for (int i = 1; i < N + 1; i++)
            maxWeight = max(maxWeight, paths[i]);
        
        if (maxWeight == INT_MAX)
            return -1;
        
        return maxWeight;
    }
};
