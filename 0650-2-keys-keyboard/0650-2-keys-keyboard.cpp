class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return dfs(1, 1, 1, n, dp);
    }
    
    int dfs(int step, int val, int copy, int n, vector<vector<int>>& dp) {        
        if(step > n || val > n) return INT_MAX;
        if(n == val) return step;
        if(dp[step][val] != -1) return dp[step][val];
    
        return dp[step][val] = min(dfs(step+1, val+copy, copy, n, dp), dfs(step+2, 2*val, val, n, dp));
    }
};