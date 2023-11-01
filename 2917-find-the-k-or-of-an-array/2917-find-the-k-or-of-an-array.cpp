class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector cnt(31, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int j = 0;
            while(n) {
                cnt[j++] += n % 2;
                n /= 2;
            }
        }
        
        int res = 0;
        for(int i = 0; i < 31; i++) {
            if(cnt[i] >= k) {
                res += pow(2, i);
            }
        }
        
        return res;
    }
};