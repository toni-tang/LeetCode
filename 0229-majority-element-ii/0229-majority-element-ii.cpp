class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto n : nums) {
            mp[n]++;
        }
        
        int n = nums.size();
        int k = n/3;
        vector<int> res;
        for(auto [key, val] : mp) {
            if(val > k) {
                res.push_back(key);
            }
        }
        
        return res;
    }
};