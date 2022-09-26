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
            if(nums[i] == maxAND)
            {
                count++;
                cout << nums[i] << endl;
            } 
            else
            {
                count = 0;  
            } 
            res = max(res,count);
        }
        
        return res;
    }
};