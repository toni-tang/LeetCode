class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        
        for(auto& n : nums) {
            mp[n]++;
        }
        
        int res = 0, prev = 0;
        for(auto it = mp.end(); it != mp.begin(); it--) {
            res += it->second + prev;
            prev += it->second;
        }
        
        return res;
    }
};