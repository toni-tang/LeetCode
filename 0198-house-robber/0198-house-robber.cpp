class Solution {
public:
// Recursive:
//     int rob(vector<int>& nums) {
//         return solve(nums, 0);
//     }
    
//     int solve(vector<int>& nums, int i) {
//         if(i == nums.size()-1 || i == nums.size()-2) return nums[i];
//         if(i >= nums.size()) return 0;
        
//         return max(nums[i] + solve(nums, i+2), solve(nums, i+1));
//     }
    
// Memoization: 
//     int rob(vector<int>& nums) {
//         int n = nums.size();        
//         vector<int> dp(nums.size(), -1);
//         return solve(nums, 0, dp);
//     }
    
//     int solve(vector<int>& nums, int i, vector<int>& dp) {
//         if(i >= nums.size()) return 0;
//         if(dp[i] > -1) return dp[i];
        
//         return dp[i] = max(nums[i] + solve(nums, i+2, dp), solve(nums, i+1, dp));
//     }

// Tabulation:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return nums[0]; 
        vector<int> dp(nums.size()+1, 0);
        
        dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }
        
        return dp[n];
    }
};