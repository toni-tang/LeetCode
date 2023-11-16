class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        if(s.size() < 10) return {};
        
        for(int i = 0; i <= s.size()-10; i++) {
            mp[s.substr(i, 10)]++;
        }
        
        vector<string> res;
        for(auto& [k, v] : mp) {
            if(mp[k] >= 2) {
                res.push_back(k);
            }
        }
        
        return res;
    }
};