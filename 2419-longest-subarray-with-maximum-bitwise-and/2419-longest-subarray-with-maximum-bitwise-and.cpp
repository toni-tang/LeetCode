class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = 0;
        int res = 0;
        int count = 0;
        
        for(auto& n : nums)
        {
            maxAND = max(maxAND, n);
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(maxAND == nums[i])
            {
                count++;
                res = max(res,count);
            }
            else if(nums[i] > maxAND)
            {
                res = 1;
                count = 1;
            } 
            else
            {
                count = 0;
            }
        }
        
        return res;
    }
};