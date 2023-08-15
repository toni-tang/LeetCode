class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') { 
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i > grid.size()-1 || i < 0 || j > grid[0].size()-1 || j < 0 || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};