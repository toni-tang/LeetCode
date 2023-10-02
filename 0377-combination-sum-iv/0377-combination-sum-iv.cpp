class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        
        for(int i = 0 ; i < nums.size(); i++) {
           dfs(nums, target, dp);
        }
        
        // for(auto n : dp) {
        //     cout << n << " ";
        // }
        // cout << endl;
        
        return dp[target];
    }
    
    int dfs(vector<int>& nums, int target, vector<int>& dp) {
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        
        if(dp[target] != -1) return dp[target];
    
        int paths = 0;
        for(int j = 0; j < nums.size(); j++) {
            paths += dfs(nums, target - nums[j], dp);  
        }
        
        return dp[target] = paths;
    }
};