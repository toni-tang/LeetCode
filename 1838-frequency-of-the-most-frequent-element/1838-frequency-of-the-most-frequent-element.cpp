class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = 0;
        long long sum = 0;
        for(int L = 0, R = 0; R < n; R++) {
            sum += nums[R];
            
            while((long) nums[R]*(R-L+1) - sum > k) {
                sum -= nums[L];
                L++;
            }
            
            res = max(res, R-L+1);
        }
        
        return res;
    }
};