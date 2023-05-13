class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
        for(int i = 0; i < strs[0].size(); i++)
        {
             char c = strs[0][i];
            
            for(string s : strs) 
            {
                if(s[i] != c ) return res;
            }
            
            res.push_back(c);
        }
        
        return res;
    }
};