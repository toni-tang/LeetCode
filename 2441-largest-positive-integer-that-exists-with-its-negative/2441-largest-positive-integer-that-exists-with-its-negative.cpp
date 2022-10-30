class Solution {
public:
    int findMaxK(vector<int>& nums) {
        if(nums.size() < 2) return -1;
        int res = -1;
        // int L = 0, R = nums.size()-1;
        
        // sort(nums.begin(), nums.end());
        
        // for(; L <= nums.size()-1 && R >= 0;)
        // {
        //     if(abs(nums[L]) == abs(nums[R]) && R != L && !(nums[R] < 0 && nums[L] < 0) && !(nums[R] > 0 && nums[L] > 0))
        //     {
        //         return nums[R];
        //     } 
        //     if(abs(nums[L]) < abs(nums[R]))
        //     {
        //         R--;
        //     }
        //     else if(abs(nums[L]) > abs(nums[R]))
        //     {
        //         L++;   
        //     }
        //     else
        //     {
        //         R--;
        //         L++;
        //     }
        // }
        
        unordered_map<int,int> mp;

        for(auto it : nums)
        {
            mp[it]++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(-nums[i]) != mp.end())
            {
                res = max(nums[i], res);
            }
        }

        return res;
    }
};