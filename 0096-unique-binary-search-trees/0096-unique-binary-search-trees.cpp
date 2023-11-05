class Solution {
public:
// Recursion:
//     int numTrees(int n) {
//         if(n == 1 || n == 0) return 1;
//         int res = 0;
        
//         for(int i = 1; i <= n; i++) {
//             res += numTrees(i-1) * numTrees(n-i);
//         }
            
//         return res;
//     }
    
// Memoization:
//     int numTrees(int n) {
//         vector<int> dp(n+1, -1);
//         return solve(n, dp);
//     }
    
//     int solve(int n, vector<int>& dp) {
//         if(n == 1 || n == 0) return 1;
//         if(dp[n] > -1) return dp[n];
//         int res = 0;
        
//         for(int i = 1; i <= n; i++) {
//             res += solve(i-1, dp) * solve(n-i, dp);
//         }
            
//         return dp[n] = res;
//     }

// Tabulation:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        

        for(int i = 2; i <= n; i++) {
            int total = 0;
            for(int j = 1; j <= i; j++) {
                int left = j - 1;
                int right = i - j;
                total += dp[left] * dp[right];
            }
            
            dp[i] = total;
        }
        
        return dp[n];
    }
};