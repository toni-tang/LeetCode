class Solution {
public:
    int averageValue(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int count = 0;
        int sum = 0;
        
        for(int &x : nums)
        {
            if(x%6 == 0) 
            {
                sum += x;
                count++;
            }
        }
                
        return count > 0 ? sum/count : 0;
    }
};