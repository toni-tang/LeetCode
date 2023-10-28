class Solution {
public:
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         vector<int> dp(target+1, 0);
    
//         for(int j = 0; j < nums.size(); j++) {
//             for(int i = target; i >= nums[j]; i--) {
//                 if(i - nums[j] == 0 || dp[i - nums[j]]) {
//                     dp[i] = max(dp[i], dp[i - nums[j]] + 1);
//                 }
//             }
//         }
    
//         return dp[target] == 0 ? -1 : dp[target];
//     }
    
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int target){
        if(target == 0) return 0;               
        if(target < 0 || i >= nums.size()) return -1001;   
        if(dp[i][target] != - 1) return dp[i][target];    

        int take = 1 + solve(nums, i+1, target - nums[i]); 
        int notTake = solve(nums, i+1, target);          

        return dp[i][target] = max(take, notTake);        
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(1001, vector<int>(1001, -1));            
        int ans = solve(nums, 0, target);                  
        return ans > 0 ? ans : -1;                         
    }
};