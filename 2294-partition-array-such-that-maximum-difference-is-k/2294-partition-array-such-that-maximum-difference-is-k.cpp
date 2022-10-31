class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size() < 1) return 0;
        int res = 1;

        sort(nums.begin(), nums.end());
        
        for(int i = 0, j = 0; j < nums.size();)
        {
            if(nums[j] > nums[i] + k)
            {
                i = j;
                res++;
            }
            else if(nums[j] <= nums[i] + k)
            {
                j++;
            }
        }


        return res;
    }
};