class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int n = s.size();
        
        unordered_map<char, unordered_set<char>> mp;
        
        for(int i = 0; i <= n-3; i++) {
            if(mp.find(s[i]) == mp.end()) {
                for(int j = n-1; j > i; j--) {
                    if(s[i] == s[j]) {
                        for(int k = i + 1; k < j; k++) {
                            mp[s[i]].insert(s[k]);
                        }
                        break;
                    }
                }
            }
        }
        
        for(auto [k, v] : mp) {
            res += v.size();
        }
        
        return res;
    }
};