class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        
        for(int i = 0, j = 0; i < t.length(); i++)
        {
            if(s[j] == t[i])
            {
                j++;
            }
            if(j == s.length()) return true;
        }
        
        return false;
    }
};