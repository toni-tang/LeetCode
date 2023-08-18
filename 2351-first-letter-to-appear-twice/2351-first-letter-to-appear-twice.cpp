class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> vec(26, false);
        for(auto c : s) {
            if(vec[c - 'a'] == true) return c;
            vec[c - 'a'] = true;
        }
        
        return 'a';
    }
};