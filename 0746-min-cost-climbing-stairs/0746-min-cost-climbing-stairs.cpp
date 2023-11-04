class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
    
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        if(i > cost.size()-1) return 0;
        if(dp[i] > 0) return dp[i];
        
        return dp[i] = min(solve(cost, i+1, dp), solve(cost, i+2, dp)) + cost[i];
    }
};