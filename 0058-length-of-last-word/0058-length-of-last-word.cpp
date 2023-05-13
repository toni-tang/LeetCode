class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        bool word = 0;
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == ' ' && res != 0)
            {
                word = 1;
            }
            else if(s[i] != ' ' && word == 0)
            {
                res++;
            }
        }
        
        return res;
    }
};