class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, 0);
        return res;
    }

private: 
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start) {
        if(start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); ++i) {
            if(i > start && nums[i] == nums[start]) {
                continue;
            }
            swap(nums[i], nums[start]);
            backtrack(res, nums, start+1);
        }
        
        for (int i = nums.size() - 1; i > start; --i) {
            swap(nums[i], nums[start]);
        }
    }
};