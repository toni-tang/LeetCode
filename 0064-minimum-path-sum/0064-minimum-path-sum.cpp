class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(i == 1) {
                     dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
                }
                else if(j == 1) {
                    dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j] + grid[i-1][j-1], dp[i][j-1] + grid[i-1][j-1]);   
                }
            }
        }
        
        return dp[m][n];
    }
};