class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 > nums[i] && i+1 < nums[i+1]) res++;
        }
        if(nums[0] != 0) res++;
        return res;
    }
};