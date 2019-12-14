class Solution { 
private:
    
    int rowChange[4] = {-1, 0, 0, 1};
    int colChange[4] = {0, -1, 1, 0};
    
public:
    
    bool isPossible(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        return (i >= 0 && i < (int)grid.size()) && (j >= 0 && j < (int)grid[i].size()) && (grid[i][j] == '1' && !visited[i][j]);
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
            if (isPossible(row + rowChange[i], col + colChange[i], grid, visited))
                dfs(grid, visited, row + rowChange[i], col + colChange[i]);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        vector<vector<bool>> visited(rows);
        for (int i = 0; i < rows; i++)
            visited[i].resize(cols, 0);
        
        int islands = 0;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
