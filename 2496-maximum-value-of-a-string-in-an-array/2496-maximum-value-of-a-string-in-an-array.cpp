class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int count = 0;
        int res = 0;
        
        for(string& s: strs)
        {
            count = 0;
            for(int i = 0; i < s.length(); i++)
            {
                if(!isdigit(s[i]))
                {
                    count = s.length();
                    break;
                }
                else
                {
                    count *= 10;
                    count += (int)s[i] - '0';
                }
            }
            res = max(count, res);
        }
        
        return res;
    }
};