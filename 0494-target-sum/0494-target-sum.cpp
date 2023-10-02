class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return dfs(nums, target, 0, 0, dp);
    }
    
    int dfs(vector<int>& nums, int target, int i, int sum, map<pair<int, int>, int>& dp) {
        if(i == nums.size()-1) {
            return (sum - nums[i] == target) + (sum + nums[i] == target);
        } 
        
        if(dp.find({i, sum}) != dp.end()) return dp[{i, sum}];
        
        return dp[{i, sum}] = dfs(nums, target, i+1, sum + nums[i], dp) + dfs(nums, target, i+1, sum - nums[i], dp);
    }
};