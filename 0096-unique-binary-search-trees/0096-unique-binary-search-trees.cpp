class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    
    int solve(int n, vector<int>& dp) {
        if(n == 1 || n == 0) return 1;
        if(dp[n] > -1) return dp[n];
        int res = 0;
        
        for(int i = 1; i <= n; i++) {
            res += solve(i-1, dp) * solve(n-i, dp);
        }
            
        return dp[n] = res;
    }
};