class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> smallestRight(nums.size(), nums.back());
        
        for(int i = nums.size()-2; i >= 0; i--) {
            smallestRight[i] = min(smallestRight[i+1], nums[i]);
        }
        
        int smallestLeft = nums[0], res = -1;
        
        for(int i = 1; i < nums.size()-1; i++) {
            if(smallestLeft < nums[i] && smallestRight[i] < nums[i]) {
                if(res != -1) res = min(res, smallestLeft + nums[i] + smallestRight[i]);
                else res = smallestLeft + nums[i] + smallestRight[i];
            }
            
            smallestLeft = min(smallestLeft, nums[i]);
        }
        
        return res;
    }
};