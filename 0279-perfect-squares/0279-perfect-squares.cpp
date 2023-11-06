class Solution {
public:
// Recursive:
//     int numSquares(int n) {
//         int res = INT_MAX;
//         solve(n, 0, res);
//         return res;
//     }
    
//     void solve(int n, int cnt, int& res) {
//         if(n == 0) {
//             res = min(res, cnt);
//             return;
//         }
        
//         if(n < 0) return;
        
//         for(int i = 1; i <= n; i++) {
//             solve(n - pow(i, 2), cnt + 1, res);
//         }
        
//         return;
//     }
    
// Tabulation:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            } 
        } 
        
        return dp[n];
    }
};