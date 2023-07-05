class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(auto& n : nums1) {
            mp[n]++;
        }
        
        for(auto& n : nums2) {
            if(mp.find(n) != mp.end()) {
                res.push_back(n);
                mp.erase(mp.find(n));
            }
        }
        
        return res;
    }
};