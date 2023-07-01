class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        
        for(const auto& n : nums) {
            sum += n;
            res = min(sum, res);
        }
        
        return (-res) + 1;
    }
};