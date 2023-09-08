class Solution {
public:
    int maxScore(vector<int>& nums) {
        int res = 0;
        long long sum = 0;

        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > 0) res++;
            else {
                break;
            }
        }
        
        return res;
    }
};