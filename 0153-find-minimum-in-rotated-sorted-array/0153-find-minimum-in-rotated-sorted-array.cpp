class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
            
        int L = 0, R = nums.size()-1;
        while(L <= R) 
        {
            int mid = L + (R - L)/2;
            res = min(res, nums[mid]);
            
            if(nums[L] <= nums[mid]) 
            {
                if(nums[R] < nums[L])
                {
                    L = mid + 1;
                }
                else
                {
                    R = mid - 1;
                }
            }
            else 
            {
                if(nums[L] > nums[R])
                {
                    R = mid - 1;
                } 
                else
                {
                    L = mid + 1;
                }
            }
           
        }
            
            
            
        return res;
    }
};