class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        return min(climb(cost, 0, dp), climb(cost, 1, dp));
    }
private:
    int climb(vector<int>& cost, int i, vector<int>& dp) {
        if(i > cost.size()-1) {
            return 0;
        }
        
        if(dp[i] > 0) {
            return dp[i];
        }
        
        int res = min(climb(cost, i+1, dp), climb(cost,i+2, dp)) + cost[i];
        dp[i] = res;
        
        return res;
    }
};