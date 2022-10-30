class Solution {
public:
    int averageValue(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int count = 0;
        int sum = 0;
        
        for(int &x : nums)
        {
            if(x%3 == 0 && x%2 == 0) 
            {
                sum += x;
                count++;
            }
        }
        
        if(sum == 0 || count == 0) return 0;
        
        return sum/count;
    }
};