class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        
        int buy = prices[0];
        for(int i = 0; i < n; i++) {
            if(prices[i] - buy > 0) {
                res += prices[i] - buy;
                buy = prices[i];
            }
            
            buy = min(buy, prices[i]);
        }
        
        return res;
    }
};