class Solution {
public:
    int string_to_int(string s) {
        int mins = 0;
        for(int i = 0; i < s.size(); i++) { mins = mins * 10 + s[i] - '0'; }
        return mins;
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> res;
        unordered_map<string, vector<int>> mp;
        
        for(auto& times : access_times) {
            int time = string_to_int(times[1].substr(0, 2)) * 60 + string_to_int(times[1].substr(2));
            mp[times[0]].push_back(time);
        }
        
        for(auto& [k, v] : mp) {
            vector<int> sweep(1441, 0);
            
            for(auto& time : v) {
                sweep[time]++;
                if(time + 60 < 1441) sweep[time + 60]--;
            }
            
            int cnt = 0;
            for(int i = 0; i < 1441; i++) {
                cnt += sweep[i];
                
                if(cnt >= 3) {
                    res.push_back(k);
                    break;
                }
            }
        }
        
        return res;
    }
};