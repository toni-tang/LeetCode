class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], pos = nums[0], neg = nums[0];
        
        for(int i = 1; i < n; i++) {
            int tmp = pos;
            pos = max({ pos * nums[i], neg * nums[i], nums[i] });
            neg = min({ tmp * nums[i], neg * nums[i], nums[i] });
            
            res = max({res, pos, neg});
        }
        
        return res;
    }
    
};