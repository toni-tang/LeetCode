class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int res = 0;
        for(auto& n : arr) {
            res = min(res + 1, n);
        }
        
        return res;
    }
};