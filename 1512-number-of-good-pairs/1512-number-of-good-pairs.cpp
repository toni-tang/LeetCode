class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            res += mp[nums[i]]++;
        }
        
        return res;
    }
};