class Solution {
public:
    int find(int v, vector<int>& parents)
    {
        if (v == parents[v])
            return v;
        return parents[v] = find(parents[v], parents);
    }
    
    bool Union(pair<int, int> p, vector<int>& parents, vector<int>& depth)
    {
        int r1 = find(p.first, parents);
        int r2 = find(p.second, parents);
        
        if (r1 != r2)
        {
            if (depth[r1] < depth[r2])
                swap(r1, r2);
            else if (depth[r1] == depth[r2])
                depth[r1]++;
            parents[r2] = r1;
            return true;
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> parents(size + 1);
        for (int i = 0; i < size + 1; i++)
            parents[i] = i;
        vector<int> depth(size + 1, 0);  
        pair <int, int> ans;
        
        for (int i = 0; i < size; i++)
        {
            if (!Union({edges[i][0], edges[i][1]}, parents, depth))
            {
                ans.first = edges[i][0];
                ans.second = edges[i][1];
            }   
        }
        
        return {ans.first, ans.second};
    }
};
