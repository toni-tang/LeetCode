class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(n, 0));
        
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                curr[i][0] = 0 ;
                break;
            }
            else if(grid[i][0] == 0) {
                curr[i][0] = -1;
            }
        }
        
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1) {
                curr[0][j] = 0 ;
                break;
            }
            else if(grid[0][j] == 0) {
                curr[0][j] = -1;
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 0) {
                    curr[i][j] = curr[i-1][j] + curr[i][j-1];
                } else if(grid[i][j] == 1) {
                    curr[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                cout << curr[i][j] << " ";
            }
            cout << endl;
        }
        
        return -curr[m-1][n-1];
    }
};