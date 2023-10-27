class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<pair<int, int>> dp(nums.size());
        
        dp[0] = make_pair(nums[0], nums[0]);
        
        for(int i = 1; i < n; i++) {
            int pos = max(max(dp[i-1].first * nums[i], dp[i-1].second * nums[i]), nums[i]);
            int neg = pos;
            if(min(min(dp[i-1].first * nums[i], dp[i-1].second * nums[i]), nums[i]) < 0) {
                neg = min(min(dp[i-1].first * nums[i], dp[i-1].second * nums[i]), nums[i]);
            }
            
            dp[i] = make_pair(pos, neg);
            res = max(res, max(dp[i].first, dp[i].second));
        }
        
        return res;
    }
    
};