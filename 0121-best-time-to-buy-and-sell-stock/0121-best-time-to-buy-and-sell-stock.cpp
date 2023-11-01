class Solution {
public:
// Brute Force:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         int n = prices.size();
        
//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 res = max(res, prices[j] - prices[i]);
//             }
//         }
        
//         return res;
//     }

// Recursive: 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0; 
        
        int res = 0;
        int prev = prices[0];
        
        for(int i = 1; i < n; i++) {
            res = max(res, prices[i] - prev);
            prev = min(prices[i], prev);
        }
        
        return res;
    }
};