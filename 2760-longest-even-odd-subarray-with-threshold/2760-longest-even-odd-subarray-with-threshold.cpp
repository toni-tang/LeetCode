class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0] % 2 == 0 && nums[0] <= threshold;
        
        int res = 0;
        int i = 0, last = INT_MAX;
        while(i < nums.size()) {
            if(nums[i] > threshold || (i > 0 && (nums[i] % 2) == (nums[i-1] % 2))) {
                res = max(res, i - last);
                last = INT_MAX;
            }
            if(last == INT_MAX && nums[i] <= threshold && nums[i] % 2 == 0) {
                last = i;
            }
            i++;
        }
        
        res = max(res, i - last);
        
        return res;
    }
};