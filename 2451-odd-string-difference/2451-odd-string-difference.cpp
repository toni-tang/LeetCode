class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> mp;
        string res = "";
        
        for(string &s : words)
        {
            vector<int> temp;
            for(int i = 0; i < s.length()-1; i++)
            {
                temp.push_back(s[i+1] - s[i]);
            }
            mp[temp].push_back(s);
        }
        
        for(auto &it: mp) 
        {
            if(it.second.size()==1) 
            {
                res = it.second[0];
                break;
            }
        }
        
        return res;
    }
};