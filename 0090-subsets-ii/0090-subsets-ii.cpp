class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        backtrack(res, nums, temp, 0);
        
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, int start)  {
        res.push_back(temp);
        
        for(int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            backtrack(res, nums, temp, i+1);
            temp.pop_back();
        }
    }
};