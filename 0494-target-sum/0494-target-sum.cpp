class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        dfs(nums, target, 0, 0, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, int i, int sum, int& res) {
        if(i >= nums.size()) return;
        if(i == nums.size()-1) {
            if(sum - nums[i] == target) {
                res++;
            }
            if(sum + nums[i] == target) {
                res++;
            }
            return;
        } 
        
        dfs(nums, target, i+1, sum + nums[i], res);
        dfs(nums, target, i+1, sum - nums[i], res);
    }
};