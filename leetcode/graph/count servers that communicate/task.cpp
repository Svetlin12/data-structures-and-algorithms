class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int sizeRows = (int)grid.size(), sizeCols = (int)grid[0].size();
        vector<int> rows(sizeRows, 0), cols(sizeCols, 0);
        int ans = 0;
        for (int i = 0; i < sizeRows; i++)
        {
            for (int j = 0; j < sizeCols; j++)
            {
                if (grid[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        for (int i = 0; i < sizeRows; i++)
            for (int j = 0; j < sizeCols; j++)
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
                    ans++;
        
        return ans;
    }
};
