class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]) res = max(res, calcArea(i, j, grid));
            }
        }

        return res;
    }
private:
    int calcArea(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + calcArea(i+1, j, grid) + calcArea(i-1, j, grid) + calcArea(i, j+1, grid) + calcArea(i, j-1, grid);        
    }
};