class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int res = 0;
        for(int i = n-1; i > 0; --i) {
            if(nums[i] != nums[i-1]) {
               res += n - i;
            }
        }
    
        return res;
    }
};