class Solution {
public:
// Recursive: 
//     int rob(vector<int>& nums) {
//         return solve(nums, nums.size()-1);
//     }
    
//     int solve(vector<int>& nums, int i) {
//         if(i < 0) {
//             return 0;
//         }
        
//         return max(nums[i] + solve(nums, i-2), solve(nums, i-1));
//     }

// Memoization (Top-Down):
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         solve(nums, n-1, dp);
//         return max(dp[n-1], dp[n-1]);
//     }
    
//     int solve(vector<int>& nums, int i, vector<int>& dp) {
//         if(i < 0) {
//             return 0;
//         }
//         if(dp[i] != -1) return dp[i];
//         return dp[i] = max(nums[i] + solve(nums, i-2, dp), solve(nums, i-1, dp));
//     }
    
// Tabulation (Bottom- Up):
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        
        dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }
        
        return dp[n];
    }
};