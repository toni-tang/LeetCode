class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(4, nums.size());
        
        for(auto n : nums) {
            dp[n]--;
            dp[2] = min(dp[2], dp[1]);
            dp[3] = min(dp[2], dp[3]);
        }
        
        return dp[3];
    }
};