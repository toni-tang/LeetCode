class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
    
        for(int j = 0; j < nums.size(); j++) {
            for(int i = target; i >= nums[j]; i--) {
                if(i - nums[j] == 0 || dp[i - nums[j]]) {
                    dp[i] = max(dp[i], dp[i - nums[j]] + 1);
                }
            }
        }
    
        return dp[target] == 0 ? -1 : dp[target];
    }
};