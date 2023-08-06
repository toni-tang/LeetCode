class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    countIsland(i, j, grid);
                    res++;
                } 
            }
        }

        return res;
    }
private: 
    void countIsland(int i, int j, vector<vector<char>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        countIsland(i+1, j, grid);
        countIsland(i-1, j, grid);
        countIsland(i, j+1, grid);
        countIsland(i, j-1, grid);
    }
};