// Recursive
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int res = 0;
//         dfs(nums, target, 0, 0, res);
//         return res;
//     }
    
//     void dfs(vector<int>& nums, int target, int i, int sum, int& res) {
//         if(i >= nums.size()) return;
//         if(i == nums.size()-1) {
//             if(sum - nums[i] == target) {
//                 res++;
//             }
//             if(sum + nums[i] == target) {
//                 res++;
//             }
//             return;
//         } 
        
//         dfs(nums, target, i+1, sum + nums[i], res);
//         dfs(nums, target, i+1, sum - nums[i], res);
//     }
// };

// Memoization (Top-Down)
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         map<pair<int, int>, int> dp;
//         return dfs(nums, target, 0, 0, dp);
//     }
    
//     int dfs(vector<int>& nums, int target, int i, int sum, map<pair<int, int>, int>& dp) {
//         if(i == nums.size()-1) return (sum - nums[i] == target) + (sum + nums[i] == target);
        
//         if(dp.find({i, sum}) != dp.end()) return dp[{i, sum}];
        
//         return dp[{i, sum}] = dfs(nums, target, i+1, sum + nums[i], dp) + dfs(nums, target, i+1, sum - nums[i], dp);
//     }
// };

// Tabulation (Bottom-Up)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        
        dp[0][0] = 1; // Level 0 / Initial Start
        for(int i = 0; i < n; i++) { // Traverse through levels
            for(auto& [sum, count] : dp[i]) { // Go through every node in a level
                // Adds new sum to next level adding the count from the previous layer because thats how many numbers can go to that value after the addition
                dp[i+1][sum+nums[i]] += count;
                dp[i+1][sum-nums[i]] += count;
            }
        }
        
        return dp[n][target]; // Returns count of the target inside the map
    }
};