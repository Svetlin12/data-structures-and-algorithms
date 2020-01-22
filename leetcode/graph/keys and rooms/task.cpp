class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int curr)
    {
        visited[curr] = true;
        
        for (auto& child : rooms[curr])
            if (!visited[child])
                dfs(rooms, visited, child);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = (int)rooms.size();
        vector<bool> visited(size);
        dfs(rooms, visited, 0);
        for (int i = 0; i < size; i++)
            if (!visited[i])
                return false;
        return true;
    }
};
