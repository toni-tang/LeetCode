class Solution {
public:
    string ans = "";
    void expand(string &s , int left ,int right, int& res)
    {
        
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right])
                break;
            left--, right++;
            res++;
        }
    }
    
    int countSubstrings(string s) {
        int res = 0;
        
        for(int i = 0; i < s.size(); i++) {
            expand(s, i, i, res);
            expand(s, i, i+1, res);
        }
        
        return res;
    }
};