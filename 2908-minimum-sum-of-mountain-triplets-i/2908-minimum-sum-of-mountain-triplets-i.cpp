class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int res = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    if(nums[i] < nums[j] && nums[j] > nums[k]) {
                        if(res != -1) {
                            res = min(res, nums[i] + nums[j] + nums[k]);
                        } else {
                            res = nums[i] + nums[j] + nums[k];
                        }
                    }
                }
            } 
        }
        
        return res;
    }

};