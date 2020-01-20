class Solution {
private:
    
    unordered_map<string, vector<pair<string, double>>> adj;
    double currCoef = -1;
    
public:
    
    void convertToAdj(vector<vector<string>>& equations, vector<double>& values)
    {
        int size = (int)equations.size();

        for (int i = 0; i < size; i++)
        {
            adj[equations[i][0]].push_back({ equations[i][1], values[i] });
            adj[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
        }
    }

    void dfs(string curr, string end, double coef, unordered_map<string, bool>& visited)
    {
        if (curr == end)
        {
            currCoef = coef;
            return;
        }

        visited[curr] = true;
        for (auto& child : adj[curr])
            if (!visited[child.first])
                dfs(child.first, end, coef*child.second, visited);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        convertToAdj(equations, values);
        int size = (int)queries.size();
        vector<double> ans((int)queries.size());
        for (int i = 0; i < size; i++)
        {
            unordered_map<string, bool> visited;
            if (adj[queries[i][0]].size() != 0)
                dfs(queries[i][0], queries[i][1], 1, visited);
            ans[i] = currCoef;
            currCoef = -1;
        }
        return ans;
    }
};
