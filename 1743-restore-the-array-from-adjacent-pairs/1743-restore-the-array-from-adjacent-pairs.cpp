class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> visited;
        
        int n = adjacentPairs.size() + 1;
        for(vector<int> pair : adjacentPairs) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        
        for(auto [k, v] : mp) {
            if(v.size() == 1) {
                res.push_back(k);
                visited[k]++;
                n--;
                
                int adj = v[0];
                res.push_back(adj);
                visited[adj]++;
                n--;
                
                while(n) {
                    for(int i = 0; i < mp[adj].size(); i++) {
                        if(visited.find(mp[adj][i]) == visited.end()) {
                            res.push_back(mp[adj][i]);
                            visited[mp[adj][i]]++;
                            adj = mp[adj][i];
                            n--;
                        }
                    }
                }
                
                break;
            }
        }
        
        return res;
    }
};