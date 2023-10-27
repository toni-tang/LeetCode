class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        
        for(int i = 0; i < amount+1; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }   
            }
        }
        
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};