class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        unordered_map<int, vector<int>> mp;
        
        int n = adjacentPairs.size() + 1;
        for(vector<int> pair : adjacentPairs) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        
        for(auto [k, v] : mp) {
            if(v.size() == 1) {
                res.push_back(k);
                res.push_back(v[0]);
                break;
            }
        }
        
        while(res.size() < n) {
            int prev = res[res.size()-2], curr = res[res.size()-1];
            vector<int>& pairs = mp[curr];
            pairs[0] == prev ? res.push_back(pairs[1]) : res.push_back(pairs[0]);
        }
        
        return res;
    }
};