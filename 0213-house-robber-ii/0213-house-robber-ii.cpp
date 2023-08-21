class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(robber(numsA), robber(numsB));
    }
private:
    int robber(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        
        dp[1] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);     
        }
         
        return dp[nums.size()];
    }
};